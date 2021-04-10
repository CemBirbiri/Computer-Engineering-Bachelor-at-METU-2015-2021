#include "ext2.h"

#include <fcntl.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#include <stdlib.h>

#define BASE_OFFSET 1024 /* location of the superblock in the first group */
void read_superblock_();
void read_super_block_ext2();
void find_block_numbers(unsigned int *arr, int *n,
        struct inode *inode, filldir_t callback());
//void find_block_numbers_lookup(struct ext2_inode *inode, struct ext2_dir_entry *dir);
int find_block_numbers_lookup(struct inode *inode, struct dentry *new_dir);
struct inode *seek_to_inode_and_read(unsigned int inode_num, struct inode * i);
void read_inode(struct inode *i);
int fd;
struct super_block super;
unsigned int *dummy_block, *dummy_block1, *dummy_block2, *empty_block;
unsigned int block_size, nblockptrs;
struct inode * inode_we_are_reading;
struct ext2_inode * inode_we_are_reading_ext2;
struct ext2_group_desc group;
struct super_block * new_super_block;
struct ext2_super_block super_block_ext2;



struct super_operations s_op;
struct inode_operations i_op;
struct file_operations f_op;

char fs_name[] = "ext2";


void initialize_block_size_relateds(){
  
  read_super_block_ext2();
    block_size = 1024 << super_block_ext2.s_log_block_size; // by definition
  

  // alloc memory to keep and indirect block temporarily
    dummy_block = malloc(block_size);
    dummy_block1 = malloc(block_size);
    dummy_block2 = malloc(block_size);

    // block pointers per block
    nblockptrs = block_size / sizeof(unsigned int*);

}

/*This function reads the contents of file f into the buffer buf provided by the 
user.The read operation starts from the o byte of the file and reads len bytes. 
It returns the number of bytes read.*/
ssize_t f_op_read(struct file *f, char *buf, size_t len, loffset_t *o)  {
  
  lseek(fd, *o, SEEK_SET);
  return read(fd, buf, len);
}

/* This function repositions the offset of the file f to o bytes relative to the 
beginning of the file,the current file offset, or the end of the file, depending 
on whether whence is SEEK_SET, SEEK_CUR, or SEEK_END ,respectively. It returns the 
resulting file position in the argument result.*/
loffset_t f_op_llseek(struct file *f, loffset_t o, int whence){
  if(whence == SEEK_SET){
    return lseek(fd, o, SEEK_SET);
  }
  else if(whence==SEEK_CUR){
    return lseek(fd, o, SEEK_CUR);
  }
  else if(whence==SEEK_END){
    return lseek(fd, o, SEEK_END);
  }
}
/*This function reads the file pointed by inode i and fills the file struct f.
It returns zero for successful operation.*/
int f_op_open(struct inode *i, struct file *f){
  //return open(i, O_RDONLY);
  
    
    f->f_inode = i;              /* inode of the file */
    f->f_op = i->f_op; /* pointer to file operations */
    f->f_flags = i->i_flags;               /* permissions */
    f->f_mode = i->i_mode;                     /* mode(type) of file */
    //f->f_pos =  i->i_size;                    /* cursor offset of the file */
    f->f_pos = 0;

  return 0;
}
/* This function is called when a file is closed.It performs clean up 
operations if necessary. Returns zero for successful operation.*/
int f_op_release(struct inode *i, struct file *f){
  
  f->f_inode = NULL;
  return 0;

}


/*This function reads the contents of the link in dir into the buffer buf provided by 
the user. The read operation reads len bytes and returns the number of bytes read.*/
/* readlink: reads the contents of the link itself */
int readlinkk(struct dentry *dir, char *buf, int len){

  return readlink(dir->d_name,buf,len);
}

/*This function calls the callback for every directory entry in inode i . 
It returns the total number of entries in the directory.*/
/* readdir: for every directory entry in data of passed in inode, it calls the
  callback function passed in with the second parameter. */
int readdir(struct inode *i, filldir_t callback){

  read_super_block_ext2() ;
  unsigned int *allblocks = malloc(sizeof(unsigned int) * super_block_ext2.s_blocks_count);
  
  
    int nallblocks = 0;

    find_block_numbers(allblocks, &nallblocks, i, callback);
    return nallblocks;


}


/*This function fills in the fields of kstat structure, stats with the information from 
the object pointed by the directory entry dir . It returns zero for successful operation.*/
/* getattr: fills in the kstat structure for the file pointed by the directory
   * entry */
int getattr(struct dentry *dir, struct kstat *stats) {


  stats->ino = dir->d_inode->i_ino;
  stats->mode = dir->d_inode->i_mode;
  stats->nlink = dir->d_inode->i_nlink;
  stats->uid = dir->d_inode->i_uid;
  stats->gid = dir->d_inode->i_gid;
  stats->size = dir->d_inode->i_size;
  stats->atime = dir->d_inode->i_atime;
  stats->mtime = dir->d_inode->i_mtime;
  stats->ctime = dir->d_inode->i_ctime;
  
  //block_size = 1024 << super_block_ext2.s_log_block_size;

  stats->blksize = block_size;

  stats->blocks = dir->d_inode->i_blocks;
  return 0;
}

/*This function fills in the fields of kstatfs struct stats with the information 
from the superblock sb . Returns zero for successful operations.*/
int statfs(struct super_block *sb, struct kstatfs *stats){
  //printf("-----------statfs-----------\n");


stats-> name = sb->s_type->name;

stats->f_magic = sb->s_magic;
stats->f_bsize = sb->s_blocksize;
stats->f_blocks = sb->s_blocks_count;
stats->f_bfree = sb->s_free_blocks_count;
stats->f_inodes = sb->s_inodes_count;
stats->f_finodes = sb->s_free_inodes_count;
stats->f_inode_size = sb->s_inode_size;
stats->f_minor_rev_level = sb->s_minor_rev_level;
stats->f_rev_level = sb->s_rev_level;

stats->f_namelen = strlen(stats->name);



  return 0;
}
unsigned int block_offset(unsigned int nblocks) {

    

    return block_size * (nblocks-1);
}



void seek_to_inode(unsigned int inode_num) {


    lseek(fd, BASE_OFFSET + block_offset(group.bg_inode_table) +

            (inode_num-1) * sizeof(struct inode), SEEK_SET);
}



struct inode *seek_to_inode_and_read(unsigned int inode_num, struct inode * i) {


    lseek(fd, BASE_OFFSET + block_offset(group.bg_inode_table) +

            (inode_num-1) * sizeof(struct inode), SEEK_SET);
    read(fd, &i, sizeof(struct inode));
    return i;
}




void seek_to_inode_ext2(unsigned int inode_num) {

    lseek(fd, BASE_OFFSET + block_offset(group.bg_inode_table) +

            (inode_num-1) * sizeof(struct ext2_inode), SEEK_SET);
}

// read first group descriptor, as only one block group we have
void read_group_descriptor() {

    lseek(fd, BASE_OFFSET+ block_size, SEEK_SET);
    read(fd, &group, sizeof(struct ext2_group_desc));
}
/* read_inode: assumes the passed in inode has its inode number set correctly
and reads and populates the remaining fields of the passed in inode */
/*This function assumes that only the inode number field (i_ino ) of the 
passed  in inode i is valid and the fucntion reads and populates the 
remaining fields of i.*/
void read_inode(struct inode *i){


    read_group_descriptor();
    struct ext2_inode *inode_we_are_reading_ext2 = malloc(sizeof(struct ext2_inode));
    seek_to_inode_ext2(i->i_ino);
    read(fd, inode_we_are_reading_ext2, sizeof(struct ext2_inode));




  i->i_mode = inode_we_are_reading_ext2->i_mode;               
  i->i_nlink = inode_we_are_reading_ext2->i_links_count;         
  i->i_uid = inode_we_are_reading_ext2->i_uid;               
  i->i_gid = inode_we_are_reading_ext2->i_gid;   

  i->i_size = inode_we_are_reading_ext2-> i_size;            
  i->i_atime = inode_we_are_reading_ext2->i_atime;         
   i->i_mtime = inode_we_are_reading_ext2->i_mtime;          
   i->i_ctime = inode_we_are_reading_ext2->i_ctime; 

   for(int j=0; j<15; j++){
    i->i_block[j] = inode_we_are_reading_ext2->i_block[j];
    //printf("i->i_block[j] =%d\n",i->i_block[j]);
   }

         
  //i->i_blocks = inode_we_are_reading_ext2->i_blocks;        
   i->i_blocks = inode_we_are_reading_ext2->i_blocks;      
  i->i_op =&i_op; 
  i->f_op = &f_op;  
  i->i_sb = &super;
   i->i_sb->s_op = &s_op;   
  i->i_flags = inode_we_are_reading_ext2->i_flags;         



  

} 
/*This function assumes that only the name field ( d_name ) of the directory entry 
dir is valid and searches for it in the directory pointed by inode i . If a matching 
directory entry is found, it fills the rest of the directory entry dir . It returns 
the pointer to the filled directory entry.*/
/* lookup: searches for the name of the passed in directory entry in the data
   of the inode, if found it fills the rest of the directory entry. */
struct dentry *lookup(struct inode *i, struct dentry *dir){
  
  if(find_block_numbers_lookup(i, dir) ==1)
    return dir;
  else
    return NULL;
}



void read_super_block_ext2() {
 
    lseek(fd, BASE_OFFSET, SEEK_SET);
    read(fd, &super_block_ext2, sizeof(struct ext2_super_block));
}

/*This function allocates and fills the fields of the superblock of the file system
fs returning a pointer to the allocated struct super_block .*/
struct super_block *get_superblock(struct file_system_type *fs){
    
    read_super_block_ext2(fs->file_descriptor);
    initialize_block_size_relateds();
    //super.s_op = &s_op;
    //super.s_type = ;


   new_super_block =malloc(sizeof(struct super_block));
   

    new_super_block->s_inodes_count =super_block_ext2.s_inodes_count;      
    new_super_block->s_blocks_count =super_block_ext2.s_blocks_count;     
    new_super_block-> s_free_blocks_count =super_block_ext2. s_free_blocks_count; 
    new_super_block-> s_free_inodes_count =super_block_ext2. s_free_inodes_count; 
    new_super_block-> s_first_data_block =super_block_ext2. s_first_data_block;

    new_super_block-> s_blocksize =1024 << super_block_ext2.s_log_block_size;  //****      
    
    new_super_block-> s_blocksize_bits =super_block_ext2.s_log_block_size;
    new_super_block-> s_blocks_per_group =super_block_ext2. s_blocks_per_group;  
    new_super_block-> s_inodes_per_group =super_block_ext2. s_inodes_per_group;  
    new_super_block-> s_minor_rev_level =super_block_ext2. s_minor_rev_level; 
    new_super_block-> s_rev_level =super_block_ext2. s_rev_level;         
    new_super_block-> s_first_ino =super_block_ext2. s_first_ino;         
    new_super_block-> s_inode_size =super_block_ext2. s_inode_size ;      
    new_super_block-> s_block_group_nr =super_block_ext2. s_block_group_nr;  
    
    new_super_block-> s_maxbytes =999; //*******     
    new_super_block->s_type =&myfs; 
    new_super_block->s_op = &s_op ; 

    new_super_block->s_flags =0; //*******           
    new_super_block->s_magic =super_block_ext2.s_magic; 
    new_super_block->s_fs_info =NULL; //******* 

    struct inode * i = malloc(sizeof(struct inode));
    i->i_ino = 2; 
    read_inode(i);
    
    unsigned int block_number = i->i_block[0];
 
    lseek(fd, BASE_OFFSET + block_offset(block_number), SEEK_SET);
    struct  dentry *root_dir = malloc(sizeof(struct dentry));
    //read(fd, root_dir, sizeof(struct dentry));

unsigned int inode_buf;
    unsigned short rec_len_buf; 
    unsigned char name_len_buf; 
    unsigned char file_type_buf;  
                      
                      read(fd, &inode_buf, sizeof(unsigned int));
                      read(fd, &rec_len_buf, sizeof(unsigned short));
                      read(fd, &name_len_buf, sizeof(unsigned char));
                      
                      read(fd, &file_type_buf, sizeof(unsigned char ));
                      
                      char name_buf[name_len_buf];
                      
                      read(fd, &name_buf, sizeof(char *) );
                    

    root_dir->d_name = name_buf;
    //printf("root_dir->d_name %s\n",root_dir->d_name);
    root_dir->d_inode = i;
    root_dir->d_parent = root_dir;
    root_dir->d_sb = new_super_block;
    root_dir->d_fsdata = NULL;
    root_dir->d_flags=0;       

    new_super_block->s_root =root_dir;   //*******       
    
  

    //printf("get_superblock bitis\n");
   return new_super_block;
}


/* Implement functions in s_op, i_op, f_op here */

struct file_system_type *initialize_ext2(const char *image_path) {
  
  //initialize_block_size_relateds();
  //printf("-----------initialize_ext2-----------------\n");
  /* fill super_operations s_op */
  /* fill inode_operations i_op */
  /* fill file_operations f_op */
  /* for example:
      s_op = (struct super_operations){
        .read_inode = your_read_inode_function,
        .statfs = your_statfs_function,
      };
  */
  s_op = (struct super_operations){
    .read_inode = (*read_inode),
    .statfs = (*statfs),
    s_op.x=100
  };

  f_op = (struct file_operations){
    f_op.llseek = f_op_llseek,
    f_op.f_op_read = f_op_read,
    f_op.f_op_open = f_op_open,
    f_op.release = f_op_release
  };

  i_op = (struct inode_operations){
    i_op.lookup = lookup,
    i_op.readlinkk = readlinkk,
    i_op.readdir = readdir,
    i_op.getattr = getattr
  };
  //struct file_system_type myfs;
  myfs.name = fs_name;
  myfs.file_descriptor = open(image_path, O_RDONLY);
  myfs.get_superblock = get_superblock;
  /* assign get_superblock function
     for example:
        myfs.get_superblock = your_get_superblock;
  */
  fd = myfs.file_descriptor;
  //printf("initialize_ext2 bitis\n");
  return &myfs;
}


int find_block_numbers_lookup(struct inode *inode, struct dentry *neww_dir) {
  //printf("-----------find_block_numbers_lookup-----------\n");

    struct dentry * new_dir;
    unsigned int block_number;
    
    unsigned int inode_buf;
    unsigned short rec_len_buf; 
    unsigned char name_len_buf; 
    unsigned char file_type_buf;

    for (int i = 0; i < 12; i++) {
      
        block_number = inode->i_block[i];
        

        if (block_number != 0) {
          //printf("look_up ici block_number = %d,  i== %d\n",block_number,i);

          lseek(fd, BASE_OFFSET + block_offset(block_number),
                        SEEK_SET);
          //read(fd, new_dir, sizeof(struct ext2_dir_entry));
          
          read(fd, &inode_buf, sizeof(unsigned int));
          read(fd, &rec_len_buf, sizeof(unsigned short));
          read(fd, &name_len_buf, sizeof(unsigned char));
          //printf("name_len_buf %d\n",name_len_buf);
          read(fd, &file_type_buf, sizeof(unsigned char ));
          
          char name_buf[name_len_buf];
          
          read(fd, &name_buf, sizeof(char *) );
          //printf("strcmp(name_buf,neww_dir->d_name)  %d\n",strcmp(name_buf,neww_dir->d_name));
          //printf("name_buf ==%s len= %d\n",name_buf, strlen(name_buf));
          //printf("neww_dir->d_name ==%s len= %d\n",neww_dir->d_name, strlen(neww_dir->d_name));
          //printf("neww_dir->d_name == name_buf %d\n",neww_dir->d_name==name_buf);
          if(!strcmp(name_buf,neww_dir->d_name)){
            struct inode * inodee = malloc(sizeof(struct inode));
            inodee->i_ino = inode_buf;
            read_inode(inodee);
            neww_dir-> d_inode = inodee;
            //neww_dir->d_parent =?
            //neww_dir->d_parent = malloc(sizeof(struct ext2_dir_entry));
            //lseek(fd, BASE_OFFSET + block_offset(block_number)+rec_len_buf,SEEK_SET);
            //read(fd, neww_dir->d_parent, sizeof(struct ext2_dir_entry));

            //neww_dir-> d_sb = new_super_block;

          }        
          return 1;
          /*if(new_dir->d_name == dir->d_name){
            dir->d_flags = new_dir->d_flags;       
            dir->d_inode = new_dir->d_inode;      
            dir->d_parent = new_dir->d_parent;    
                         
            dir->d_sb = new_dir->d_sb;   
            dir->d_fsdata = new_dir->d_fsdata; 
            }*/
          }
    }

    // indrect - order 1
    block_number = inode->i_block[12];

    if (block_number != 0) {

        
        lseek(fd, BASE_OFFSET + block_offset(block_number), SEEK_SET);
        read(fd, dummy_block, block_size);

        for (unsigned int i = 0; i < nblockptrs; i++) {
            block_number = dummy_block[i];
            //printf("look_up ici block_number = %d\n",block_number);

            if (block_number != 0) {
               //printf("look_up ici block_number = %d,  i== %d\n",block_number,i);

              lseek(fd, BASE_OFFSET + block_offset(block_number),
                            SEEK_SET);
              //read(fd, new_dir, sizeof(struct ext2_dir_entry));
              
              read(fd, &inode_buf, sizeof(unsigned int));
              read(fd, &rec_len_buf, sizeof(unsigned short));
              read(fd, &name_len_buf, sizeof(unsigned char));
              //printf("name_len_buf %d\n",name_len_buf);
              read(fd, &file_type_buf, sizeof(unsigned char ));
              
              char name_buf[name_len_buf];
              
              read(fd, &name_buf, sizeof(char *) );
              //printf("strcmp(name_buf,neww_dir->d_name)  %d\n",strcmp(name_buf,neww_dir->d_name));
              //printf("name_buf ==%s len= %d\n",name_buf, strlen(name_buf));
              //printf("neww_dir->d_name ==%s len= %d\n",neww_dir->d_name, strlen(neww_dir->d_name));
              //printf("neww_dir->d_name == name_buf %d\n",neww_dir->d_name==name_buf);
              if(!strcmp(name_buf,neww_dir->d_name)){
                struct inode * inodee = malloc(sizeof(struct inode));
                inodee->i_ino = inode_buf;
                read_inode(inodee);
                neww_dir-> d_inode = inodee;
                //neww_dir->d_parent =?
            //neww_dir->d_parent = malloc(sizeof(struct ext2_dir_entry));
            //lseek(fd, BASE_OFFSET + block_offset(block_number)+rec_len_buf,SEEK_SET);
            //read(fd, neww_dir->d_parent, sizeof(struct ext2_dir_entry));

            //neww_dir-> d_sb = new_super_block;

              }        
              return 1;
             /*if(new_dir->d_name == dir->d_name){
                dir->d_flags = new_dir->d_flags;       
                dir->d_inode = new_dir->d_inode;      
                dir->d_parent = new_dir->d_parent;    
                             
                dir->d_sb = new_dir->d_sb;   
                dir->d_fsdata = new_dir->d_fsdata; 
                }*/
            }
        }
    }

    // indrect - order 2
    block_number = inode->i_block[13];
    
    if (block_number != 0) {

        lseek(fd, BASE_OFFSET + block_offset(block_number), SEEK_SET);
        read(fd, dummy_block, block_size);
       
        for (unsigned int i = 0; i < nblockptrs; i++) {

            block_number = dummy_block[i];

            if (block_number != 0) {

                lseek(fd, BASE_OFFSET + block_offset(block_number), SEEK_SET);
                read(fd, dummy_block1, block_size);

                for (unsigned int j = 0; j < nblockptrs; j++) {

                    block_number = dummy_block1[j];
                    //printf("look_up ici block_number = %d\n",block_number);

                    if (block_number != 0) {
                    //printf("look_up ici block_number = %d,  i== %d\n",block_number,i);

                      lseek(fd, BASE_OFFSET + block_offset(block_number),
                                    SEEK_SET);
                      //read(fd, new_dir, sizeof(struct ext2_dir_entry));
                      
                      read(fd, &inode_buf, sizeof(unsigned int));
                      read(fd, &rec_len_buf, sizeof(unsigned short));
                      read(fd, &name_len_buf, sizeof(unsigned char));
                      //printf("name_len_buf %d\n",name_len_buf);
                      read(fd, &file_type_buf, sizeof(unsigned char ));
                      
                      char name_buf[name_len_buf];
                      
                      read(fd, &name_buf, sizeof(char *) );
                      //printf("strcmp(name_buf,neww_dir->d_name)  %d\n",strcmp(name_buf,neww_dir->d_name));
                      //printf("name_buf ==%s len= %d\n",name_buf, strlen(name_buf));
                      //printf("neww_dir->d_name ==%s len= %d\n",neww_dir->d_name, strlen(neww_dir->d_name));
                      //printf("neww_dir->d_name == name_buf %d\n",neww_dir->d_name==name_buf);
                      if(!strcmp(name_buf,neww_dir->d_name)){
                        struct inode * inodee = malloc(sizeof(struct inode));
                        inodee->i_ino = inode_buf;
                        read_inode(inodee);
                        neww_dir-> d_inode = inodee;
                        //neww_dir->d_parent =?
            //neww_dir->d_parent = malloc(sizeof(struct ext2_dir_entry));
            //lseek(fd, BASE_OFFSET + block_offset(block_number)+rec_len_buf,SEEK_SET);
            //read(fd, neww_dir->d_parent, sizeof(struct ext2_dir_entry));

            //neww_dir-> d_sb = new_super_block;

                      }        
                      return 1;
                            /*if(new_dir->d_name == dir->d_name){
                                dir->d_flags = new_dir->d_flags;       
                                dir->d_inode = new_dir->d_inode;      
                                dir->d_parent = new_dir->d_parent;    
                                             
                                dir->d_sb = new_dir->d_sb;   
                                dir->d_fsdata = new_dir->d_fsdata; 
                                }*/
                    }
                }
            }
        }
    }

    // indrect - order 3
    block_number = inode->i_block[14];
    
    if (block_number != 0) {

        lseek(fd, BASE_OFFSET + block_offset(block_number), SEEK_SET);
        read(fd, dummy_block, block_size);
       
        for (unsigned int i = 0; i < nblockptrs; i++) {

            block_number = dummy_block[i];

            if (block_number != 0) {

                lseek(fd, BASE_OFFSET + block_offset(block_number), SEEK_SET);
                read(fd, dummy_block1, block_size);

                for (unsigned int j = 0; j < nblockptrs; j++) {

                    block_number = dummy_block1[j];

                    if (block_number != 0) {

                        lseek(fd, BASE_OFFSET + block_offset(block_number), SEEK_SET);
                        read(fd, dummy_block2, block_size);

                        for (unsigned int k = 0; k < nblockptrs; k++) {

                            block_number = dummy_block2[k];
                              //printf("look_up ici block_number = %d\n",block_number);
                            if (block_number != 0) {
                              //printf("look_up ici block_number = %d,  i== %d\n",block_number,i);

                                lseek(fd, BASE_OFFSET + block_offset(block_number),
                                              SEEK_SET);
                                //read(fd, new_dir, sizeof(struct ext2_dir_entry));
                                
                                read(fd, &inode_buf, sizeof(unsigned int));
                                read(fd, &rec_len_buf, sizeof(unsigned short));
                                read(fd, &name_len_buf, sizeof(unsigned char));
                                //printf("name_len_buf %d\n",name_len_buf);
                                read(fd, &file_type_buf, sizeof(unsigned char ));
                                
                                char name_buf[name_len_buf];
                                
                                read(fd, &name_buf, sizeof(char *) );
                                //printf("strcmp(name_buf,neww_dir->d_name)  %d\n",strcmp(name_buf,neww_dir->d_name));
                                //printf("name_buf ==%s len= %d\n",name_buf, strlen(name_buf));
                                //printf("neww_dir->d_name ==%s len= %d\n",neww_dir->d_name, strlen(neww_dir->d_name));
                                //printf("neww_dir->d_name == name_buf %d\n",neww_dir->d_name==name_buf);
                                if(!strcmp(name_buf,neww_dir->d_name)){
                                  struct inode * inodee = malloc(sizeof(struct inode));
                                  inodee->i_ino = inode_buf;
                                  read_inode(inodee);
                                  neww_dir-> d_inode = inodee;
                                  //neww_dir->d_parent =?
                                  //neww_dir->d_parent =?
            //neww_dir->d_parent = malloc(sizeof(struct ext2_dir_entry));
            //lseek(fd, BASE_OFFSET + block_offset(block_number)+rec_len_buf, SEEK_SET);
            //read(fd, neww_dir->d_parent, sizeof(struct ext2_dir_entry));

            //neww_dir-> d_sb = new_super_block;

                                }        
                                return 1;
                                        /*if(new_dir->d_name == dir->d_name){
            dir->d_flags = new_dir->d_flags;       
            dir->d_inode = new_dir->d_inode;      
            dir->d_parent = new_dir->d_parent;    
                         
            dir->d_sb = new_dir->d_sb;   
            dir->d_fsdata = new_dir->d_fsdata; 
            }*/
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

void find_block_numbers(
unsigned int *arr, int *n,
        struct inode *inode, filldir_t callback())
{
  //printf("-----------find_block_numbers_lookup-----------\n");

    struct dentry * neww_dir;
    unsigned int block_number;
    
    unsigned int inode_buf;
    unsigned short rec_len_buf; 
    unsigned char name_len_buf; 
    unsigned char file_type_buf;

    for (int i = 0; i < 12; i++) {
      
        block_number = inode->i_block[i];
        

        if (block_number != 0) {
          //printf("look_up ici block_number = %d,  i== %d\n",block_number,i);

          lseek(fd, BASE_OFFSET + block_offset(block_number),
                        SEEK_SET);
          //read(fd, new_dir, sizeof(struct ext2_dir_entry));
          
          read(fd, &inode_buf, sizeof(unsigned int));
          read(fd, &rec_len_buf, sizeof(unsigned short));
          read(fd, &name_len_buf, sizeof(unsigned char));
          //printf("name_len_buf %d\n",name_len_buf);
          read(fd, &file_type_buf, sizeof(unsigned char ));
          
          char name_buf[name_len_buf];
          
          read(fd, &name_buf, sizeof(char *) );
          callback(name_buf, name_len_buf, inode_buf);
          //printf("strcmp(name_buf,neww_dir->d_name)  %d\n",strcmp(name_buf,neww_dir->d_name));
          //printf("name_buf ==%s len= %d\n",name_buf, strlen(name_buf));
          //printf("neww_dir->d_name ==%s len= %d\n",neww_dir->d_name, strlen(neww_dir->d_name));
          //printf("neww_dir->d_name == name_buf %d\n",neww_dir->d_name==name_buf);
                  
          
          /*if(new_dir->d_name == dir->d_name){
            dir->d_flags = new_dir->d_flags;       
            dir->d_inode = new_dir->d_inode;      
            dir->d_parent = new_dir->d_parent;    
                         
            dir->d_sb = new_dir->d_sb;   
            dir->d_fsdata = new_dir->d_fsdata; 
            }*/
          }
    }

    // indrect - order 1
    block_number = inode->i_block[12];

    if (block_number != 0) {

        //printf("look_up ici block_number 12= %d\n",block_number);
        lseek(fd, BASE_OFFSET + block_offset(block_number), SEEK_SET);
        read(fd, dummy_block, block_size);

        for (unsigned int i = 0; i < nblockptrs; i++) {
            block_number = dummy_block[i];
            //printf("look_up ici block_number = %d\n",block_number);

            if (block_number != 0) {
               //printf("look_up ici block_number = %d,  i== %d\n",block_number,i);

              lseek(fd, BASE_OFFSET + block_offset(block_number),
                            SEEK_SET);
              //read(fd, new_dir, sizeof(struct ext2_dir_entry));
              
              read(fd, &inode_buf, sizeof(unsigned int));
              read(fd, &rec_len_buf, sizeof(unsigned short));
              read(fd, &name_len_buf, sizeof(unsigned char));
              //printf("name_len_buf %d\n",name_len_buf);
              read(fd, &file_type_buf, sizeof(unsigned char ));
              
              char name_buf[name_len_buf];
              
              callback(name_buf, name_len_buf, inode_buf);
          //printf("strcmp(name_buf,neww_dir->d_name)  %d\n",strcmp(name_buf,neww_dir->d_name));
          //printf("name_buf ==%s len= %d\n",name_buf, strlen(name_buf));
          //printf("neww_dir->d_name ==%s len= %d\n",neww_dir->d_name, strlen(neww_dir->d_name));
          //printf("neww_dir->d_name == name_buf %d\n",neww_dir->d_name==name_buf);        
              
             /*if(new_dir->d_name == dir->d_name){
                dir->d_flags = new_dir->d_flags;       
                dir->d_inode = new_dir->d_inode;      
                dir->d_parent = new_dir->d_parent;    
                             
                dir->d_sb = new_dir->d_sb;   
                dir->d_fsdata = new_dir->d_fsdata; 
                }*/
            }
        }
    }

    // indrect - order 2
    block_number = inode->i_block[13];
    
    if (block_number != 0) {
      //printf("look_up ici block_number 13= %d\n",block_number);

        lseek(fd, BASE_OFFSET + block_offset(block_number), SEEK_SET);
        read(fd, dummy_block, block_size);
       
        for (unsigned int i = 0; i < nblockptrs; i++) {

            block_number = dummy_block[i];

            if (block_number != 0) {
              //printf("look_up ici block_number13 = %d\n",block_number);

                lseek(fd, BASE_OFFSET + block_offset(block_number), SEEK_SET);
                read(fd, dummy_block1, block_size);

                for (unsigned int j = 0; j < nblockptrs; j++) {

                    block_number = dummy_block1[j];
                    //printf("look_up ici block_number = %d\n",block_number);

                    if (block_number != 0) {
                    //printf("look_up ici block_number = %d,  i== %d\n",block_number,i);

                      lseek(fd, BASE_OFFSET + block_offset(block_number),
                                    SEEK_SET);
                      //read(fd, new_dir, sizeof(struct ext2_dir_entry));
                      
                      read(fd, &inode_buf, sizeof(unsigned int));
                      read(fd, &rec_len_buf, sizeof(unsigned short));
                      read(fd, &name_len_buf, sizeof(unsigned char));
                      //printf("name_len_buf %d\n",name_len_buf);
                      read(fd, &file_type_buf, sizeof(unsigned char ));
                      
                      char name_buf[name_len_buf];
                      
                      read(fd, &name_buf, sizeof(char *) );
                      callback(name_buf, name_len_buf, inode_buf);
          //printf("strcmp(name_buf,neww_dir->d_name)  %d\n",strcmp(name_buf,neww_dir->d_name));
          //printf("name_buf ==%s len= %d\n",name_buf, strlen(name_buf));
          //printf("neww_dir->d_name ==%s len= %d\n",neww_dir->d_name, strlen(neww_dir->d_name));
          //printf("neww_dir->d_name == name_buf %d\n",neww_dir->d_name==name_buf);

                    }
                }
            }
        }
    }

    // indrect - order 3
    block_number = inode->i_block[14];
    
    if (block_number != 0) {
      //printf("look_up ici block_number 14= %d\n",block_number);

        lseek(fd, BASE_OFFSET + block_offset(block_number), SEEK_SET);
        read(fd, dummy_block, block_size);
       
        for (unsigned int i = 0; i < nblockptrs; i++) {

            block_number = dummy_block[i];

            if (block_number != 0) {
              //printf("look_up ici block_number 14 = %d\n",block_number);

                lseek(fd, BASE_OFFSET + block_offset(block_number), SEEK_SET);
                read(fd, dummy_block1, block_size);

                for (unsigned int j = 0; j < nblockptrs; j++) {

                    block_number = dummy_block1[j];

                    if (block_number != 0) {
                      //printf("look_up ici block_number 14= %d\n",block_number);

                        lseek(fd, BASE_OFFSET + block_offset(block_number), SEEK_SET);
                        read(fd, dummy_block2, block_size);

                        for (unsigned int k = 0; k < nblockptrs; k++) {

                            block_number = dummy_block2[k];
                              //printf("look_up ici block_number = %d\n",block_number);
                            if (block_number != 0) {
                              //printf("look_up ici block_number = %d,  i== %d\n",block_number,i);

                                lseek(fd, BASE_OFFSET + block_offset(block_number),
                                              SEEK_SET);
                                //read(fd, new_dir, sizeof(struct ext2_dir_entry));
                                
                                read(fd, &inode_buf, sizeof(unsigned int));
                                read(fd, &rec_len_buf, sizeof(unsigned short));
                                read(fd, &name_len_buf, sizeof(unsigned char));
                                //printf("name_len_buf %d\n",name_len_buf);
                                read(fd, &file_type_buf, sizeof(unsigned char ));
                                
                                char name_buf[name_len_buf];
                                
                                read(fd, &name_buf, sizeof(char *) );
                                callback(name_buf, name_len_buf, inode_buf);
          //printf("strcmp(name_buf,neww_dir->d_name)  %d\n",strcmp(name_buf,neww_dir->d_name));
          //printf("name_buf ==%s len= %d\n",name_buf, strlen(name_buf));
          //printf("neww_dir->d_name ==%s len= %d\n",neww_dir->d_name, strlen(neww_dir->d_name));
          //printf("neww_dir->d_name == name_buf %d\n",neww_dir->d_name==name_buf);        
                               
            
                            }
                        }
                    }
                }
            }
        }
    }
    
}
/*
void find_block_numbers(unsigned int *arr, int *n,
        struct inode *inode, filldir_t callback()) {
  printf("-----------find_block_numbers-----------\n");


//unsigned int *allblocks = malloc(sizeof(unsigned int) * super.s_blocks_count);

    unsigned int block_number;

    for (int i = 0; i < 12; i++) {
        block_number = inode->i_block[i];

        if (block_number != 0) {
       
            arr[*n] = block_number;
            *n = (*n + 1);
            callback();
        }
    }

    // indrect - order 1
    block_number = inode->i_block[12];

    if (block_number != 0) {

        //arr[*n] = block_number;
        //*n = (*n + 1);
        //callback;

        lseek(fd, BASE_OFFSET + block_offset(block_number), SEEK_SET);
        read(fd, dummy_block, block_size);

        for (unsigned int i = 0; i < nblockptrs; i++) {
            block_number = dummy_block[i];

            if (block_number != 0) {
           
                arr[*n] = block_number;
                *n = (*n + 1);
                callback;
            }
        }
    }

    // indrect - order 2
    block_number = inode->i_block[13];
    
    if (block_number != 0) {

        //arr[*n] = block_number;
        //*n = (*n + 1);
        //callback;

        lseek(fd, BASE_OFFSET + block_offset(block_number), SEEK_SET);
        read(fd, dummy_block, block_size);
       
        for (unsigned int i = 0; i < nblockptrs; i++) {

            block_number = dummy_block[i];

            if (block_number != 0) {

                //arr[*n] = block_number;
                //*n = (*n + 1);
                //callback;

                lseek(fd, BASE_OFFSET + block_offset(block_number), SEEK_SET);
                read(fd, dummy_block1, block_size);

                for (unsigned int j = 0; j < nblockptrs; j++) {

                    block_number = dummy_block1[j];

                    if (block_number != 0) {
                    
                        arr[*n] = block_number;
                        *n = (*n + 1);
                        callback;
                    }
                }
            }
        }
    }

    // indrect - order 3
    block_number = inode->i_block[14];
    
    if (block_number != 0) {

        //arr[*n] = block_number;
        //*n = (*n + 1);
        //callback;

        lseek(fd, BASE_OFFSET + block_offset(block_number), SEEK_SET);
        read(fd, dummy_block, block_size);
       
        for (unsigned int i = 0; i < nblockptrs; i++) {

            block_number = dummy_block[i];

            if (block_number != 0) {

                //arr[*n] = block_number;
                //*n = (*n + 1);
                //callback;

                lseek(fd, BASE_OFFSET + block_offset(block_number), SEEK_SET);
                read(fd, dummy_block1, block_size);

                for (unsigned int j = 0; j < nblockptrs; j++) {

                    block_number = dummy_block1[j];

                    if (block_number != 0) {

                        //arr[*n] = block_number;
                        //*n = (*n + 1);
                        //callback;

                        lseek(fd, BASE_OFFSET + block_offset(block_number), SEEK_SET);
                        read(fd, dummy_block2, block_size);

                        for (unsigned int k = 0; k < nblockptrs; k++) {

                            block_number = dummy_block2[k];

                            if (block_number != 0) {
                            
                                arr[*n] = block_number;
                                *n = (*n + 1);
                                callback;
                            }
                        }
                    }
                }
            }
        }
    }
}



*/













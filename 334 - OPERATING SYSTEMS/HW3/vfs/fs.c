#include "fs.h"
#include "ext2_fs/ext2.h"
//#include "ext2_fs/ext2.c"

#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int init_fs(const char *image_path) {
  //printf("init_fs   image_path = > %s\n", image_path);

  current_fs = initialize_ext2(image_path);



  current_sb = current_fs->get_superblock(current_fs);
  
  //printf( "x---->%d\n ",current_sb->s_op->x);
  
  

  return !(current_fs && current_sb);
}

struct file *openfile(char *path) {
  struct file *f = malloc(sizeof(struct file));
  f->f_path = malloc(strlen(path) + 1);
  strcpy(f->f_path, path);
  struct dentry *dir = pathwalk(path);
  if (!dir) {
    return NULL;
  }
  f->f_inode = dir->d_inode;
  free(dir);
  if (f->f_inode->f_op->f_op_open(f->f_inode, f)) {
    return NULL;
  }
  return f;
}

int closefile(struct file *f) {
  if (f->f_op->release(f->f_inode, f)) {
    printf("Error closing file\n");
  }
  free(f);
  f = NULL;
  return 0;
}

int readfile(struct file *f, char *buf, int size, loffset_t *offset) {
  if (*offset >= f->f_inode->i_size) {
    return 0;
  }
  if (*offset + size >= f->f_inode->i_size) {
    size = f->f_inode->i_size - *offset;
  }
  // May add llseek call***********************************************
  return f->f_op->f_op_read(f, buf, size, offset);
}

char** split_path(char *path, char **p){
  int count=1;
  char * path2 = malloc(sizeof(strlen(path)));
  
  for(int i=0; i< strlen(path); i++){
    path2[i] = path[i];
  }
  //printf("path2 = %s\n",path2);
  //printf("path[0] = %s\n",path[0]);
  if(path[1]==NULL){
    
    p= malloc(sizeof(char *) * 1);
    
    p[0] = calloc(1,sizeof(char));
    
    p[0] = ".";
    //p[0] = path[0];
    
  }
  else{

    
    char* token = strtok(path, "/");   
    while (token != NULL) { 
        
        count=count+1; 
        token = strtok(NULL, "/"); 
    }
   

    
    p = malloc(sizeof(char*) * count+1);
    
    //printf("path2 = %s\n",path2);
    token = strtok(path2, "/"); 
  
    // Keep printing tokens while one of the 
    // delimiters present in str[]. 
    //p[0]= calloc(1,sizeof(char));
    //p[0] = ".";
    int i=0;
    while (token != NULL) { 
        //printf("token = %s\n",token);
        p[i]= calloc(strlen(token),sizeof(char));
        p[i] = token;
        token = strtok(NULL, "/");
        i++; 
        
    }

    
  }
  //for(int i=0; i<3 ; i++){
    //printf("-> %s\n", p[i]);
  //}
  //printf("yokartik %s\n", p[0]);
return p;
  
}


/*This function takes an absolute path, path as a C string
(e.g. /home/config) and returns its directory entry. If the
 path cannot be found it returns NULL .*/
struct dentry *pathwalk(char *path) {
  /* Allocates and returns a new dentry for a given path */
    //printf("-----------pathwalk------------\n");

  char **p;
  p= split_path(path,p);
  int p_len =0, j=0;
  while(p[j]!= NULL){
    //printf("aaa = %s %d\n", p[j], j);
    j++;

  }
  p_len = j;
  //printf("p_len -> %d\n", p_len);
  initialize_block_size_relateds();

  /*printf("pathwalk girdi-1 \n");
  struct inode *inode2;
  printf("pathwalk girdi-2 \n");
  inode2 = malloc(sizeof(struct inode));
  inode2->i_ino =2;  
  read_inode(inode2);
  printf("pathwalk girdi-4 \n");*/


  struct inode *inode2;
  inode2 = malloc(sizeof(struct inode));
  


  struct dentry * dir_return;
  dir_return= malloc(sizeof(struct dentry));

  struct dentry * dir_temp;
  dir_temp= malloc(sizeof(struct dentry)); 

  struct dentry * dir_temp2;
  dir_temp2= malloc(sizeof(struct dentry)); 
  //dir->d_name = p[0];
  
  for(int i=0; i< p_len; i++){
    if(i==0){
      inode2->i_ino =2;
      read_inode(inode2);
      //printf("0\n");
      //printf("000 %d\n", inode2->i_block[0]);

      dir_temp->d_name = p[0];

      //printf("1\n");
      dir_return = inode2->i_op->lookup(inode2, dir_temp);
      dir_return->d_parent = dir_return;

      //printf("dir_return->d_name --> %s\n",dir_return->d_name);
      //printf("2\n");
      if(dir_return==NULL){
        //printf("3\n");
        return dir_return;
      }
      
    }
    else{

      dir_temp2 = dir_return; 
      //printf("4\n");
      inode2->i_ino = dir_return->d_inode->i_ino;
      //printf("inode2->i_ino %d\n",inode2->i_ino);
      read_inode(inode2);
      dir_temp->d_name = p[i];
      dir_return = inode2->i_op->lookup(inode2, dir_temp);
      dir_return->d_parent = dir_temp2;
      if(dir_return==NULL){
        //printf("5\n");
        return dir_return;
      }
    }

  }
  
//struct dentry *lookup(struct inode *i, struct dentry *dir)
  
  return dir_return;

}

int statfile(struct dentry *d_entry, struct kstat *k_stat) {
  return d_entry->d_inode->i_op->getattr(d_entry, k_stat);
}

import math
def divide(data, attr_index, attr_vals_list):
    """Divides the data into buckets according to the selected attr_index.
    :param data: Current data in the node
    :param attr_index: Selected attribute index to partition the data
    :param attr_vals_list: List of values that attributes may take
    :return: A list that includes K data lists in it where K is the number
     of values that the attribute with attr_index can take
    """
    attr_values = attr_vals_list[attr_index]
    divided_data=[]
    for i in range(0,len(attr_values)):
      divided_data.append([])

    for i in range(0,len(data)):
      for j in range(0,len(attr_values)):
        if data[i][attr_index]== attr_values[j]:
          divided_data[j].append(data[i])
    
    return divided_data
    #pass


def entropy(data, attr_vals_list):
    """
    Calculates the entropy in the current data.
    :param data: Current data in the node
    :param attr_vals_list: List of values that attributes may take
    (Last attribute is for the labels)
    :return: Calculated entropy (float)
    """
    import math
    count=[]
    entropies=[]
    attr_values=attr_vals_list[-1] 
    for i in range(0,len(attr_values)):
      count.append(0)
      entropies.append(0)

    for i in range(0,len(data)):
      for j in range(0,len(attr_values)):
        if data[i][-1]==attr_values[j]:
          count[j]+=1
    
    for i in range(0,len(count)):
      if count[i]!=0:
        S= (-1.0)*(count[i]/len(data))*math.log((count[i]/len(data)),2)
        entropies[i]=(S)
      else:
        entropies[i]=(0)

    sum=0
    for i in range(0,len(entropies)):
      sum+=entropies[i]

    return sum
    #pass


def info_gain(data, attr_index, attr_vals_list):
    """
    Calculates the information gain on the current data when the attribute with attr_index is selected.
    :param data: Current data in the node
    :param attr_index: Selected attribute index to partition the data
    :param attr_vals_list: List of values that attributes may take
    :return: information gain (float), buckets (the list returned from divide)
    """
    entropy_total_data= entropy(data, attr_vals_list)
    divided_data= divide(data, attr_index, attr_vals_list)
    entropies=[]
    S=0

    for i in range(0,len(divided_data)):
      S= entropy(divided_data[i], attr_vals_list)
      entropies.append(S)
    
    ig=entropy_total_data
    
    for i in range(0,len(entropies)):
      ig= ig- ((len(divided_data[i])/ len(data))* entropies[i])
   
    return ig, divided_data
    #pass


def gain_ratio(data, attr_index, attr_vals_list):
    """
    Calculates the gain ratio on the current data when the attribute with attr_index is selected.
    :param data: Current data in the node
    :param attr_index: Selected attribute index to partition the data
    :param attr_vals_list: List of values that attributes may take
    :return: gain_ratio (float), buckets (the list returned from divide)
    """
    import math
    entropy_total_data= entropy(data, attr_vals_list)
    ig , divided_data= info_gain(data, attr_index, attr_vals_list)
    entropies=[]
    S=0

    for i in range(0,len(divided_data)):
      S= entropy(divided_data[i], attr_vals_list)
      entropies.append(S)
    
    IntI = 0
    for i in range(0,len(entropies)):
      temp=abs(len(divided_data[i]))/abs(len(data))
      if (temp)!=0:
        x=(-1.0)*(temp)*math.log((temp),2)
        IntI= IntI+x

    return (ig/IntI), divided_data
    #pass


def gini(data, attr_vals_list):
    """
    Calculates the gini index in the current data.
    :param data: Current data in the node
    :param attr_vals_list: List of values that attributes may take
    (Last attribute is for the labels)
    :return: Calculated gini index (float)
    """
    count=[]
    attr_values=attr_vals_list[-1]
    for i in range(0,len(attr_values)):
      count.append(0)
    for i in range(0,len(data)):
      for j in range(0,len(attr_values)):
        if data[i][-1]==attr_values[j]:
          count[j]+=1
    proportion=[]
    for i in range(0,len(count)):
      if len(data)!=0:
        proportion.append( (count[i]/len(data)) * (count[i]/len(data)) )
      else:
        proportion.append(0)
    gini_value=1
    for i in range(0,len(proportion)):
      gini_value-= proportion[i]

    return gini_value
    #pass


def avg_gini_index(data, attr_index, attr_vals_list):
    """
    Calculates the average gini index on the current data when the attribute with attr_index is selected.
    :param data: Current data in the node
    :param attr_index: Selected attribute index to partition the data
    :param attr_vals_list: List of values that attributes may take
    :return: average gini index (float), buckets (the list returned from divide)
    """
    divided_data=divide(data, attr_index, attr_vals_list)

    avg_gini=0
    for i in range(0,len(divided_data)):
      avg_gini+= len(divided_data[i])/len(data) * gini(divided_data[i],attr_vals_list)
    return avg_gini, divided_data

def chi_squared_test(data, attr_index, attr_vals_list):
    """
    Calculated chi squared and degree of freedom between the selected attribute and the class attribute
    :param data: Current data in the node
    :param attr_index: Selected attribute index to partition the data
    :param attr_vals_list: List of values that attributes may take
    :return: chi squared value (float), degree of freedom (int)
    """
    pass

Array::Array(int size = 1):size(size){
  head = new T[size];
  current_end = 0;
  }

bool Array::indexinbounds(int &index)const{
  (index<size&&index>=0)?return True:False;
}

void Array::extendhead(int &bylength = 10){
  T* temphead = NULL;
  for(int i =0;i<5||temphead!=NULL;i++){
    temphead = new T[size+bylength]
  }
  if (temphead==NULL) throw -1;
  else {
    for(int i=0;i<size;i++){
      temphead[i]=head[i];
    }
    head = temphead;
    size+=bylength;
  }
}

void Array::push_back(T value){      
  if(current_end=size){
    extendhead();
  }
  head[current_end++]=value;  
}

T& Array::operator[](int index)const{
  if (indexinbounds(index))return head[index];
  else throw -1;
}

void Array::insert(T &value, int &index){
  if(!indexinbounds(index)){
    throw -1;
  }
  else{
    if(index>=current_end){
      head[index] = value;
      current_end = index;
    }
    else {
      if(!indexinbounds(current_end)){
        extendhead();
      }
      for(int i=current_end;i>index;i--){
       head[i]=head[i-1];
      }
      head[index]=value
    }
  }
}

int& Array::length(){return current_end;}


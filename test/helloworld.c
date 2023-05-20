int c = 5;
int add(int a,int b){
    int res = a+b;
    return res;
}


int main(){
    double d = 1.1;
    int a = 1;
    a = add(3,4);
    int b = 1;
    if(a==3){
        b = b+1;
    }else{
        b = b-1;
    }
    return 0;
}
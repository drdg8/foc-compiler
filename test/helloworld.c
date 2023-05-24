int add(int a,int b){
    int res = a+b;
    return res;
}


int f[100];
int h;
// h = f[3];
// f[1] = 2;

int main(){
    
    double d = 1.1;
    int a = 1;
    a = add(3,4);
    printf("%d\n",a);
    int b = 1;
    // if(a==3){
    //     b = b+1;
    // }else{
    //     b = b-1;
    // }
    int e = 5;
    while( e < 6 ){
        if(e == 5){
            break;
        }
        e = e + 1;
        // b = b + 1;
    }
    int i;
    // for(i=0;i<2;i=i+1){
    //     e = e + i;
    // }
    printf("%d\n",b);
    printf("%d\n",e);
    int g[100];

    h = f[4];
    f[2] = e;
    return 0;
}
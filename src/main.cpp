#include <mbed.h>


Serial pc(USBTX, USBRX);

int main()
{
    char c[8];
    pc.baud(9600);  
    pc.printf("test\n");
    int res;
    int i = 0;

    while(1) 
    {  
        if(pc.readable())
        {
            //pc.printf("Start reading \n");
            res = pc.scanf("{ %s }",c);
            pc.printf("ok : %d",res);
            if(res)
            {
                if(!strcmp(c,"i"))
                {
                    pc.printf("info1\n");
                    }
                else if(!strcmp(c,"d"))
                {
                    i++;
                    pc.printf("%d",i);
                    pc.printf("info2\n");
                    }
                else 
                {
                    pc.printf("ERROR CODE\n");
                    }
            }
            else 
                pc.printf("ERROR FORMAT\n");    
        }            
    }
}



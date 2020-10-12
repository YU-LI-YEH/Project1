#include <iostream>
#include <string>
#include <fstream>
using namespace std;

typedef struct shape
{
    int r, w;
} SHAPE;
class block_data
{
    private:
        SHAPE shape[4];
        SHAPE touch_point[4];
        string block;
        int start_col;
        int tall;
    public:
        string get_block(){
            return block;
        }
        int get_start_col(){
            return start_col;
        }
        void set_block(string &x, int &y){
            block = x;
            start_col = y - 1;
            for (int i = 0; i < 4; i++)
                touch_point[i] = {-1, -1}
            if (block[0] == 'T'){
                if(block[1] == '1'){
                    shape[0] = {0,1};
                    shape[1] = {1,0};
                    shape[2] = {1,1};
                    shape[3] = {1,2};   
                    touch_point[0] = {0,1};
                    touch_point[1] = {1,0};
                    touch_point[2] = {1,2};
                    tall = 2;
                }
                else if(block[1] == '2'){
                    shape[0] = {0,1};
                    shape[1] = {1,0};
                    shape[2] = {1,1};
                    shape[3] = {2,1};  
                    touch_point[0] = {0,1};
                    touch_point[1] = {1,0};        
                    tall = 3;     
                }
                else if(block[1] == '3'){
                    shape[0] = {0,0};
                    shape[1] ={ 0,1};
                    shape[2] = {0,2};
                    shape[3] = {1,1};
                    touch_point[0] = {0,0};
                    touch_point[1] = {0,1};
                    touch_point[2] = {0,2};      
                    tall = 2;
                }
                else if(block[1] == '4'){
                    shape[0] = {0,0};
                    shape[1] = {1,0};
                    shape[2] = {1,1};
                    shape[3] = {2,0};
                    touch_point[0] = {0,0};
                    touch_point[1] = {1,1};
                    tall = 3;
                }
            }
            else if(block[0] == 'L'){
                if(block[1] == '1'){
                    shape[0] = {0,0};
                    shape[1] = {0,1};
                    shape[2] = {1,0};
                    shape[3] = {2,0};   
                    touch_point[0] = {0,0};
                    touch_point[1] = {0,1};
                    tall = 3;
                }
                else if(block[1] == '2'){
                    shape[0] = {0,0};
                    shape[1] = {1,0};
                    shape[2] = {1,1};
                    shape[3] = {1,2};  
                    touch_point[0] = {0,0};
                    touch_point[1] = {1,1};
                    touch_point[2] = {1,2};       
                    tall = 2;  
                }
                else if(block[1] == '3'){
                    shape[0] = {0,1};
                    shape[1] = {1,1};
                    shape[2] = {2,0};
                    shape[3] = {2,1};
                    touch_point[0] = {0,1};
                    touch_point[1] = {2,0};   
                    tall = 3;   
                }
                else if(block[1] == '4'){
                    shape[0] = {0,0};
                    shape[1] = {0,1};
                    shape[2] = {0,2};
                    shape[3] = {1,2};
                    touch_point[0] = {0,0};
                    touch_point[1] = {0,1};
                    touch_point[2] = {0,2};
                    tall = 2;
                }
            }
            else if(block[0] == 'J'){
                if(block[1] == '1'){
                    shape[0] = {0,0};
                    shape[1] = {0,1};
                    shape[2] = {1,1};
                    shape[3] = {2,1};   
                    touch_point[0] = {0,0};
                    touch_point[1] = {0,1};
                    tall = 3;
                }
                else if(block[1]=='2'){
                    shape[0]={0,0};shape[1]={0,1};shape[2]={0,2};shape[3]={1,0};  
                    touch_point[0]={0,0};touch_point[1]={0,1};touch_point[2]={0,2}; 
                    tall=2;        
                }
                else if(block[1]=='3'){
                    shape[0]={0,0};shape[1]={1,0};shape[2]={2,0};shape[3]={2,1};
                    touch_point[0]={0,0};touch_point[1]={2,1};    
                    tall=3;  
                }
                else if(block[1]=='4'){
                    shape[0]={0,2};shape[1]={1,0};shape[2]={1,1};shape[3]={1,2};
                    touch_point[0]={0,2};touch_point[1]={1,0};touch_point[2]={1,1};
                    tall=2;
                }
            }
            else if(block[0]=='S'){
                if(block[1]=='1'){
                    shape[0]={0,0};shape[1]={0,1};shape[2]={1,1};shape[3]={1,2};   
                    touch_point[0]={0,0};touch_point[1]={0,1};touch_point[2]={1,2};
                    tall=2;
                }
                else if(block[1]=='2'){
                    shape[0]={0,1};shape[1]={1,0};shape[2]={1,1};shape[3]={2,0};  
                    touch_point[0]={0,1};touch_point[1]={1,0};         
                    tall=3;
                }
            }
            else if(block[0]=='Z'){
                if(block[1]=='1'){
                    shape[0]={0,1};shape[1]={0,2};shape[2]={1,0};shape[3]={1,1};   
                    touch_point[0]={0,1};touch_point[1]={0,2};touch_point[2]={1,0};
                    tall=2;
                }
                else if(block[1]=='2'){
                    shape[0]={0,0};shape[1]={1,0};shape[2]={1,1};shape[3]={2,1};  
                    touch_point[0]={0,0};touch_point[1]={1,1};         
                    tall=3;
                }
            }
            else if(block[0]=='I'){
                if(block[1]=='1'){
                    shape[0]={0,0};shape[1]={1,0};shape[2]={2,0};shape[3]={3,0};   
                    touch_point[0]={0,0};
                    tall=4;
                }
                else if(block[1]=='2'){
                    shape[0]={0,0};shape[1]={0,1};shape[2]={0,2};shape[3]={0,3};  
                    touch_point[0]={0,0};touch_point[1]={0,1};touch_point[2]={0,2};touch_point[3]={0,3};    
                    tall=1; 
                }
            }
            else if(block[0]=='O'){
                shape[0]={0,0};shape[1]={0,1};shape[2]={1,0};shape[3]={1,1};  
                touch_point[0]={0,0};touch_point[1]={0,1}; 
                tall=2; 
            }

        }
            }
        }
}

int main()

while (!touches the boundary){
    cin pattern 
    for (;the upper row are not all zero; column down)
    shift left or right
    if (row has all 1) {
        clear the row 
        all others 1 goes down 
    }
}
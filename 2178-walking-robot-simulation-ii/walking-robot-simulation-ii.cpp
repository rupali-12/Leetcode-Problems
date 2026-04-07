class Robot {
    public:
    int peri;
    int dir=0;  // 0-East, 1-North, 2-west, 3-South
    int w, h, x=0, y=0;

    Robot(int width, int height) {
        w=width;
        h=height;
        peri = 2*(w+h)-4;  // to remove duplicate addition of corners
    }
    
    void step(int num) {
        if(peri ==0)return;
       num = num % peri;   // reducing loop 
        if(num==0 && (x!=0 || y!=0)) return;   
       if(num==0 && (x==0 && y==0)){  // case when moves become 0 and we reach again starting point
        dir=3; //south
        return;
       }

       while(num>0){
        if(dir==0){   // East
          int move = min(num, w-x-1);
          x+= move;
          num-=move;
          if(num>0) dir=1;
        }
        else if(dir==1){  //North
          int move = min(num, h-y-1);
          y+= move;
          num-=move;
          if(num>0) dir=2;
        }
       /* Enough space
        num = 2, x = 5
        move = min(2,5) = 2
        Hit boundary
        num = 10, x = 5
        move = min(10,5) = 5  */
        else if(dir==2){   // West
          int move = min(num, x);   // if x=5 you can move left only x 
          x-= move;
          num-=move;
          if(num>0) dir=3;
        }
        else{    // South
          int move = min(num, y);
          y-= move;
          num-=move;
          if(num>0) dir=0;
        }
       }
    }
    
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() { 
        if(dir==0) return "East";
        if(dir==1) return "North";
        if(dir==2) return "West";
        return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
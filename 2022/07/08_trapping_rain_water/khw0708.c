/*
Runtime: 17 ms, faster than 63.72% of C online submissions for Trapping Rain Water.
Memory Usage: 7.1 MB, less than 21.14% of C online submissions for Trapping Rain Water.
*/


typedef struct Peak{
    int idx;
    int height;
} peak;

//물의 양을 측정하면서 측정한곳 표시
int checkWater(peak p1, peak p2, int * flag, int * height)
{
    int max = p1.height < p2.height ? p1.height: p2.height;
    int start = p1.idx;
    int end = p2.idx;
    int warter =0;
    for(int i = start+1; i<= end-1; i++)
    {   
        if(max - height[i] > 0)
        {
            warter += (max - height[i]);
        }
    }

    return warter;
}

int trap(int* height, int heightSize){
    int flag[20000]={0,};
    int vary = 1;
    peak p[heightSize];
    peak temp;
    int peakCnt =0;
    int left = 0, right = 0;
    int left_pIdx = -1;

    if(heightSize<=2) return 0;


    for( int i=1; i< heightSize ; i++){

        if(height[i-1] <= height[i])
        {
            vary = 1;
        } else {
            if(vary == 1){
                
                temp.height = height[i-1];
                temp.idx = i-1;

                //peak 생성하면서 필요없는 건 삭제
                if(left <= temp.height)
                {
                    //left 전까지 있던 peak 다 삭제
                    peakCnt = left_pIdx+1;
                    left = temp.height;
                    left_pIdx = peakCnt;
                    right = temp.height;
                }else if(right <= temp.height)
                {
                    //temp.height 보다 작은 peak 삭제
                    int j = peakCnt-1;
                    while(p[j].height < temp.height ){
                        j--;
                    }
                    peakCnt = j+1;

                    right = temp.height;
                } else if( right > temp.height ){
                    right = temp.height;
                }
                p[peakCnt].height = height[i-1];
                p[peakCnt].idx = i-1;
                peakCnt++;
            }
            vary = -1;
        }
    }
    //마지막이 peak 인 경우
    if(vary == 1){

        temp.height = height[heightSize-1];
        temp.idx = heightSize-1;

        //peak 생성하면서 필요없는 건 삭제
        if(left <= temp.height)
        {
            //left 전까지 있던 peak 다 삭제
            peakCnt = left_pIdx+1;
            left = temp.height;
            left_pIdx = peakCnt;
            right = temp.height;
        }else if(right <= temp.height)
        {
            //temp.height 보다 작은 peak 삭제
            int j = peakCnt-1;
            while(p[j].height < temp.height ){
                j--;
            }
            peakCnt = j+1;

            right = temp.height;
        } else if( right > temp.height ){
            right = temp.height;
        }

        p[peakCnt].height = height[heightSize-1];
        p[peakCnt].idx = heightSize-1;
        peakCnt++;
    }

    int re=0;
    
    for(int i = 0; i < peakCnt-1 ; i++)
    {
        re += checkWater(p[i], p[i+1], flag, height);
    }

    return re;

}

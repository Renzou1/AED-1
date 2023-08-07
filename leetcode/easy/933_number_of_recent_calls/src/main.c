typedef struct {
    bool requests[3001];
    int previousRangeBegin;
    int rangeBegin;
    int rangeEnd;
    int requestCounter;
} RecentCounter;


RecentCounter* recentCounterCreate() {
    RecentCounter* obj = (RecentCounter*)malloc(sizeof(RecentCounter));
    for(int i = 0; i < 3001; i++)
    {
        obj->requests[i] = false;
    }

    obj-> rangeBegin = 0;
    obj-> requestCounter = 0;
    obj-> previousRangeBegin = 0;

    return obj;
}

int recentCounterPing(RecentCounter* obj, int t) {

    obj->previousRangeBegin = obj->rangeBegin;
    obj->rangeBegin = t-3000;
    if(obj->rangeBegin < 0) obj->rangeBegin = 0; //avoiding negative
    obj->rangeEnd = t;

    int shift = (obj->rangeBegin - obj->previousRangeBegin);

    if(shift > 3000)
    {
        for(int c = 0; c < 3001; c++)
        {
            obj->requests[c] = false;
        }
        obj->requestCounter = 0;

    } else{
    
        for(int i = 0; i < shift; i++)
        {   
            if(obj->requests[i] == true)
            {
                obj->requests[i] = false;
                obj->requestCounter--;
            }   
        }
    
        for(int i = shift; i < 3001; i++) 
        {
            if(obj->requests[i] == true)
            {
                obj->requests[i] = false;
                obj->requests[i-shift] = true;
            }
        }

    }

    obj->requests[obj->rangeEnd - obj->rangeBegin] = true;
    obj->requestCounter++;
    
    return obj->requestCounter;
}


void recentCounterFree(RecentCounter* obj) {
    free(obj);
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);
 
 * recentCounterFree(obj);
*/

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
        obj->requests[i] = 0;
    }

    obj-> rangeBegin = 0;
    obj->requestCounter = 0;
    return obj;
}

int recentCounterPing(RecentCounter* obj, int t) {

    obj->rangeBegin = t-3000;
    if(obj->rangeBegin < 0) obj->rangeBegin = 0;
    obj->rangeEnd = t;
    
    obj->requestCounter++;

    int shift = (obj->rangeBegin - obj->previousRangeBegin);
    

    for(int i = 0; i < shift; i++)
    {   
        if(shift > 3000)
        {
            if(i == 3001)
            {
                obj->requestCounter = 0;
                break;
            }
            obj->requests[i] = false;
            continue;
        }
        if(obj->requests[i] == true)
        {
            obj->requests[i]= false;
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
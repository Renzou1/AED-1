#define SIZE 3001
typedef struct {
    int requests[SIZE];
    int rangeBegin;
    int rangeEnd;
    int requestCounter;
} RecentCounter;

RecentCounter* recentCounterCreate() {
    RecentCounter* obj = (RecentCounter*)malloc(sizeof(RecentCounter));

    for(int i = 0; i < SIZE; i++)
    {
        obj->requests[i] = 0;
    }

    obj-> rangeBegin = 0;
    obj-> requestCounter = 0;

    return obj;
}

int recentCounterPing(RecentCounter* obj, int t) {

    obj->requestCounter++;
    bool done = false;

    for(int i = 0; i < SIZE; i++)
    {
        if(done == false && obj->requests[i] == 0)
        {
            obj->requests[i] = t;
            done = true;
        }

        if(obj->requests[i] < t-3000 && obj->requests[i] != 0)
        {
            obj->requests[i] = 0;
            obj->requestCounter--;
            i--;
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
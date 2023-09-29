int maxProfit(int* prices, int pricesSize){
    int p1, p2;
    p1 = 0;
    p2 = 1;
    int profit = 0;

    int difference = prices[p2] - prices[p1];
    while(p2 < pricesSize)
    {
        difference = prices[p2] - prices[p1];
        if(difference > profit)
        {
            profit = difference;
        }  else if(difference <= 0)
        {
            p1 = p2;
        }
        p2++;
    }
  
    return profit;
}

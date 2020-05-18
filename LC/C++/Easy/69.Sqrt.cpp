int mySqrt(int x){
    /* initialize base conditions */
   if (x == 0 || x == 1 ) return x;
   long start = 1;
   long end = x;
   long answer; 
   /* binary search */
   while(start <= end){
       long mid = (start + end)/2;
       if(mid*mid == x) return mid;
       else if(mid*mid > x){
           /* mid is already too big - search below */
           end = mid - 1;
       }
       else {
        /* mid is lesser - can be the solution */
        start = mid + 1;
        answer = mid;
       }
   }
   return answer;
}

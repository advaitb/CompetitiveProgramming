impl Solution {
    pub fn kids_with_candies(candies: Vec<i32>, extra_candies: i32) -> Vec<bool> {
        let mut ret: Vec<bool> = Vec::new();
        let max_candies = candies.iter().max().unwrap();
        for v in candies.iter() {
            if v + extra_candies >= *max_candies {
                ret.push(true);
            } else {
                ret.push(false);
            }
        }
        return ret
    }
}

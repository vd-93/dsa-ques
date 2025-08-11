class Solution {
public:
    /*M-2 - Same logic, just different code

    here we are using vector instead of stack, to avoid extra reversing at the end
    */
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;

        for(int i = 0; i < asteroids.size(); i++) {
            int currAst = asteroids[i];

            if(currAst > 0) {
                res.push_back(currAst);
            }
            // currAst < 0
            else {
                // currAst destroying smaller ast which are moving right
                while(!res.empty() && res.back() > 0 && res.back() < abs(currAst)) {
                    res.pop_back();
                }
                // curr ast and res.back() destroying each other
                if(!res.empty() && res.back() == abs(currAst)) {
                    res.pop_back();
                }
                // include curr negative ast only if the res is empty or the res.back is also negative
                else if(res.empty() || res.back() < 0) {
                    res.push_back(currAst);
                }
            }
        }

        return res;
    }

    /* M-1
    Logic:
    traverse the asteroids array,
        - if the stack is empty or the stack's top and current ast are non colliding -> add to stack
        - else (stack top and curr ast are colliding)
            pop from stack till the stack's top is smaller than abs(curr ast)
            if they are eqaul -> pop from stack and and dont add the curr ast to stack, move to next
            if curr ast smaller than st top -> dont add curr ast to stack and move to next ast

    at the end stack will be storing the asteroids, take them in array and reverse that array to get
    correct final state of asteroids
    */
    // bool nonColliding(int a, int b) {
    //     return (a > 0 && b > 0) || (a < 0 && b < 0) || (a < 0 && b > 0);
    // }
    // vector<int> asteroidCollision(vector<int>& asteroids) {
    //     vector<int> result;
    //     stack<int> st;

    //     for(int i = 0; i < asteroids.size(); i++) {
    //         int currAsteroid = asteroids[i];
            
    //         if(st.empty() || nonColliding(st.top(), currAsteroid)) {
    //             st.push(currAsteroid);
    //         }
    //         // means curr ast is negative and st top is positive
    //         else {
    //             bool includeCurrAst = true;

    //             while(!st.empty() && !nonColliding(st.top(), currAsteroid)) {
    //                 if(abs(currAsteroid) > st.top()) {
    //                     st.pop();
    //                 }
    //                 else if(abs(currAsteroid) == st.top()) {
    //                     st.pop();
    //                     includeCurrAst = false;
    //                     break;
    //                 }
    //                 else { // abs(currAsteroid < st.top())
    //                     includeCurrAst = false;
    //                     break;
    //                 }
    //             }

    //             if(includeCurrAst) {
    //                 st.push(currAsteroid);
    //             }
    //         }
    //     }

    //     while(!st.empty()) {
    //         result.push_back(st.top());
    //         st.pop();
    //     }

    //     reverse(result.begin(), result.end());
    //     return result;
    // }
};
class Solution {
public:
    /*Logic:
    traverse the asteroids array,
        - if the stack is empty or the stack's top and current ast are non colliding -> add to stack
        - else (stack top and curr ast are colliding)
            pop from stack till the stack's top is smaller than abs(curr ast)
            if they are eqaul -> pop from stack and and dont add the curr ast to stack, move to next
            if curr ast smaller than st top -> dont add curr ast to stack and move to next ast

    at the end stack will be storing the asteroids, take them in array and reverse that array to get
    correct final state of asteroids
    */
    bool nonColliding(int a, int b) {
        return (a > 0 && b > 0) || (a < 0 && b < 0) || (a < 0 && b > 0);
    }
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        stack<int> st;

        for(int i = 0; i < asteroids.size(); i++) {
            int currAsteroid = asteroids[i];
            
            if(st.empty() || nonColliding(st.top(), currAsteroid)) {
                st.push(currAsteroid);
            }
            // means curr ast is negative and st top is positive
            else {
                bool includeCurrAst = true;

                while(!st.empty() && !nonColliding(st.top(), currAsteroid)) {
                    if(abs(currAsteroid) > st.top()) {
                        st.pop();
                    }
                    else if(abs(currAsteroid) == st.top()) {
                        st.pop();
                        includeCurrAst = false;
                        break;
                    }
                    else { // abs(currAsteroid < st.top())
                        includeCurrAst = false;
                        break;
                    }
                }

                if(includeCurrAst) {
                    st.push(currAsteroid);
                }
            }
        }

        while(!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
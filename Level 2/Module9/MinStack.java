import java.util.Stack;
/*

    Min stack operation needs to run in O(1) time. Binary search tree and heap data structures
    are often great for keeping track of minimum, their core operations find, add and remove
    are log(n) time complexity. So we need to use some other data structure to keep track of minimum in O(1) time.

*/
/*
    Approach 1: Stack of Value and Minimum Pair

*/

class MinstackApproach1 {

    private Stack<int[]> stack;
    
    MinstackApproach1() {
        stack = new Stack<>();
    }

    public void push(int val) {
        if(stack.isEmpty()) {
            stack.push(new int[]{val, val});
        } else {
            stack.push(new int[]{val, Math.min(val, stack.peek()[1])});
        }
    }

    public void pop() {
        if(!stack.isEmpty()) {
            stack.pop();
        }
    }

    public int top() {
        if(!stack.isEmpty()) {
            return stack.peek()[0];
        }
        throw new RuntimeException("Stack is empty");
    }

    public int getMin() {
        if(!stack.isEmpty()) {
            return stack.peek()[1];
        }
        throw new RuntimeException("Stack is empty");
    }
}

/*
    Approach 2: Two Stacks with frequency count of minimum element


*/

public class MinStack {
    private Stack<Integer> stack;
    private Stack<int[]> minStack;

    public MinStack() {
        stack = new Stack<>();
        minStack = new Stack<>();
    }

    public void push(int val) {
        stack.push(val);
        if (minStack.isEmpty() || val < minStack.peek()[0]) {
            minStack.push(new int[]{val, 1});
        } else if (val == minStack.peek()[0]) {
            minStack.peek()[1]++;
        }
    }

    public void pop() {
        if (!stack.isEmpty()) {
            int val = stack.pop();
            if (val == minStack.peek()[0]) {
                if (minStack.peek()[1] > 1) {
                    minStack.peek()[1]--;
                } else {
                    minStack.pop();
                }
            }
        }
    }

    public int top() {
        if (!stack.isEmpty()) {
            return stack.peek();
        }
        throw new RuntimeException("Stack is empty");
    }

    public int getMin() {
        if (!minStack.isEmpty()) {
            return minStack.peek()[0];
        }
        throw new RuntimeException("Stack is empty");
    }
}

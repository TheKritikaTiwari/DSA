class FrontMiddleBackQueue {
    LinkedList<Integer> list = new LinkedList<Integer>();

    public FrontMiddleBackQueue() {
        
    }
    
    public void pushFront(int val) {
        list.addFirst(val);
    }
    
    public void pushMiddle(int val) {
        System.out.println("size" + list.size());
        int n=(list.size())/2;
        list.add(n,val);
    }
    
    public void pushBack(int val) {
        list.addLast(val);
    }
    
    public int popFront() {
        if(!list.isEmpty())
        return list.pollFirst();
        else 
        return -1;
    }
    
    public int popMiddle() {
        if(!list.isEmpty()){
            int n=(list.size()-1)/2;
            return list.remove(n);
        }
        else 
        return -1;
    }
    
    public int popBack() {
        if(!list.isEmpty())
        return list.pollLast();
        else 
        return -1;
    }
}

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue obj = new FrontMiddleBackQueue();
 * obj.pushFront(val);
 * obj.pushMiddle(val);
 * obj.pushBack(val);
 * int param_4 = obj.popFront();
 * int param_5 = obj.popMiddle();
 * int param_6 = obj.popBack();
 */
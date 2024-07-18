import java.util.Scanner;
 class Node{
    public int data;
    public Node next;
    public Node(int data){
        this.data=data;
        this.next=null;
    } 
}
 class SLinkedList{
    Node head = null;
    public void insertAtStart(int data){
        Node newNode = new Node(data);
        if(head==null){
            head=newNode;
        }
        else {
            newNode.next=head;
            head=newNode;
        }
        System.out.println("Node inserted !!");
    }
    public void insertAtEnd(int data){
        Node newNode = new Node(data);
        if(head==null){
            head=newNode;
        }
        else {
            Node temp = head;
            while(temp.next!=null){
                temp=temp.next;
            } 
            temp.next=newNode;
        }
        System.out.println("Node inserted !!");
    }
    public void insertAtMiddle(int data, int search){
        Node temp = head;
        boolean flag =false;
        while(temp!=null){
            if(temp.data==search){
                flag=true;
                break;
            }
            temp=temp.next;
        }
        if(!flag){
            System.out.println("Node not found !!");
        }
        else{
            Node newNode = new Node(data);
            Node nextNode = temp.next;
            temp.next = newNode;
            newNode.next = nextNode; 
            System.out.println("Node inserted !!"); 
        }
    }
    public void show(){
        if(head==null){
            System.out.println("Empty LinkedList");
        }
        else{
            Node temp = head;
            System.out.print("LinkedList is: ");
            while(temp!=null){
                System.out.print(temp.data+" -> ");
                temp=temp.next;
            }
            System.out.println("null");
        }
    }
    public void deleteAtStart(){
        if(head==null){
            System.out.println("No nodes present to delete");
        }
        else{
            Node temp= head;
            head=temp.next;
            temp.next=null;
            System.out.println("Element Deleted");
        }
    }
    public void deleteAtEnd(){
        if(head==null){
            System.out.println("No nodes present to delete");
        }
        else{
            Node previousNode=null;
            Node temp = head;
            while(temp.next!=null){
                previousNode=temp;
                temp=temp.next;
            }
            previousNode.next=null;
            System.out.println("Element Deleted");
        }
    }
    public void deleteAtMiddle(int search){
       Node previousNode=null,nextNode=null;
       Node temp = head;
       boolean flag =false;
        while(temp!=null){
            if(temp.data==search){
                flag=true;
                break;
            }
            previousNode=temp;
            temp=temp.next;
        }
        if(!flag){
            System.out.println("Node not found !!");
        }
        else{
            nextNode=temp.next;
            temp.next=null;
            previousNode.next=nextNode;
            System.out.println("Element Deleted");
        }
    }
}

class SinglyLinkedList{
    public static void main(String args[]){
        SLinkedList obj = new SLinkedList();
        Scanner sc=new Scanner(System.in);
        int ch,search,data;
        while(true){
            System.out.println("1. INSERT AT START");
            System.out.println("2. INSERT AT END");
            System.out.println("3. INSERT AT MIDDLE");
            System.out.println("4. SHOW");
            System.out.println("5. DELETE AT START");
            System.out.println("6. DELETE AT END");
            System.out.println("7. DELETE AT MIDDLE");
            System.out.println("0. EXIT");
            System.out.print("Enter your choice: ");
            ch=sc.nextInt();
            if(ch==0)
                break;
            if(ch==1){
                System.out.print("Enter node data: ");
                data=sc.nextInt();
                obj.insertAtStart(data);
            }
            else if(ch==2){
                System.out.print("Enter node data: ");
                data=sc.nextInt();
                obj.insertAtEnd(data);
            }
            else if(ch==3){
                System.out.print("Enter node data: ");
                data=sc.nextInt();
                System.out.print("Enter searchable data: ");
                search=sc.nextInt();
                obj.insertAtMiddle(data,search);
            }
            else if(ch==4){
                obj.show();
            }
            else if(ch==5){
                obj.deleteAtStart();
            }
            else if(ch==6){
                obj.deleteAtEnd();
            }
            else if(ch==7){
                System.out.print("Enter searchable data: ");
                search=sc.nextInt();
                obj.deleteAtMiddle(search);
            }
        }
    }
}
/**
 * stack
 */
public class stackhomework{
    public static void main(String[] args) {
        stack p = new stack(10);
        System.out.println("是不是空:"+ p.IsEmpty());
        p.push(2);
        p.push(4);
        p.push(3);
        System.out.println("现在的状态:"+ p.list());
        System.out.println("满了吗："+ p.IsFull());
        p.pop();
        p.pop();
        p.pop();
        System.out.println("是不是空:"+ p.IsEmpty());
    } 
}

/**
 * stack
 */
class stack {
    private int Maxsize;
    private int top;
    private StringBuffer stack;

    public stack(int Maxsize){
        this.Maxsize = Maxsize;
        this.stack = new StringBuffer(Maxsize);
        this.top = -1;
    }
    public boolean IsEmpty()
    {
        return this.top == -1;
    }
    public boolean IsFull()
    {
        return this.top == this.Maxsize;
    }

    public void push(int value)
    {
        if (IsFull())
        {
            System.err.println("Stack is Full!");
            return ;
        }
        stack.append(value);
        this.top++;
    }

    public void pop()
    {
        if(IsEmpty())
        {
            System.err.println("Stack is Empty!");
            return;
        }
        System.out.println("出栈的元素是："+stack.substring(this.top));
        stack.deleteCharAt(this.top);
        this.top--;
    }
    public String list()
    {
        return stack.toString();
    }
}
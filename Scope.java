package scope;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import javax.script.*;
import java.util.*;
import static java.lang.Math.abs;

public class Scope {


    public static void main(String[] args) throws FileNotFoundException, IOException, InterruptedException {
        
        
        BufferedReader br = new BufferedReader(new FileReader("D:\\example1.txt"));
        
        Stack<String> stack1 = new Stack<String>();
        Stack<String> stack2 = new Stack<String>();

        String line = null;
        int count = 0;
        while((line = br.readLine()) != null)
                {
                    
                    StringTokenizer token = new StringTokenizer(line);
                    //StringTokenizer token2 = new StringTokenizer(line);
                    
                    while(token.hasMoreTokens())
                    {
                        
                        String s = null;
                        String r = null;
                        s = token.nextToken();
                        
                        if(token.hasMoreTokens())
                        {
                            r = token.nextToken();
                            if(r.contains("("))
                            {
                                r =  r.substring(r.indexOf("(") + 1);
                                
                                if(r.contains("int") || r.contains("String") || r.contains("char"))
                                {
                                    s = r;
                                    r = token.nextToken();
                                    
                                    //System.out.println("{");
                                    printStack(stack1, stack2);
                                    System.in.read();
                                    stack1.push("------------");
                                    stack2.push("");
                                    
                                    
                                }
                                
                            }
                        }
                        
                        
                        if((s.equals("int") || s.equals("String") || s.equals("char")) && r != null && !r.contains("("))
                        {
                            
                            if(r.contains(";") || r.contains(",") || r.contains(")"))
                            {
                                stack1.push(r.substring(0,r.length()-1));
                                stack2.push(Integer.toString(count));
                            }
                            
                            else 
                            {
                                stack1.push(r);
                                stack2.push(Integer.toString(count));
                            }
                            
                            
                            if(r.contains(","))
                            {     
                                
                                r = token.nextToken();
                                if(r.contains("int") || r.contains("String") || r.contains("char"))
                                {
                                    r = token.nextToken();
                                }
                                //System.out.println(r.substring(0, 1) + " " + count)
                                if(r.contains(";") || r.contains(",") || r.contains(")"))
                                {
                                    stack1.push(r.substring(0,r.length()-1));
                                    stack2.push(Integer.toString(count));
                                }
                                else{
                                stack1.push(r);
                                stack2.push(Integer.toString(count));
                                }
                                
                            }
                        }
                            
                    }
                    
                    if(line.contains("{"))
                    {
                        printStack(stack1, stack2);
                        System.in.read();
                        stack1.push("------------");
                        stack2.push("");
                    }
                    if(line.contains("}"))
                    {
                        printStack(stack1,stack2);
                        System.in.read();
                        popStack(stack1,stack2);
                    }
                    
                    count++;
                    
                    
                        
                }
                printStack(stack1,stack2);
                System.in.read();
                while(stack1.contains("------------"))
                {
                    popStack(stack1,stack2);
                    printStack(stack1,stack2);
                    System.in.read();
                }
                    
            }
    
private static void printStack(Stack<String> s1, Stack<String> s2)
{
    Stack<String> temp1 = new Stack<String>();
    while(!s1.isEmpty())
    {
        
        temp1.push(s1.pop());
    }
    
    Stack<String> temp2 = new Stack<String>();
    while(!s2.isEmpty())
    {
        temp2.push(s2.pop());
    }
    
    
    while(!temp1.isEmpty())
    {
        
        
        System.out.printf("%-10s %-10s\n",temp1.peek(), temp2.peek());
        
        s1.push(temp1.pop());
        s2.push(temp2.pop());
        
    }
    
    System.out.print("\n");
    
}

private static void popStack(Stack<String> s1, Stack<String> s2)
{

    while(s1.peek() != "------------")
    {
        s1.pop();
        s2.pop();
    }
    

    s1.pop();
    s2.pop();
}



}

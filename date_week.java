import java.util.*;
public class date_week {
    public static void main(String[] args)
    {
        week p = new week();
        p.input_date();
        p.show_week();
        mul m = new mul();
        m.muls(5);
    }
}
//实现week功能
class week{
    String data;
    String s[];
    int year,month,day;
    void input_date(){
        Scanner input = new Scanner(System.in);
        System.out.println("请输入对应的日期按照年—月-日格式");
        this.data = input.next();
        input.close();
        this.s = this.data.split("-");
        this.year = Integer.valueOf(this.s[0]);
        this.month= Integer.valueOf(this.s[1]);
        this.day = Integer.valueOf(this.s[2]);
    };

    void show_week(){
       String weeks[] = {"星期天","星期一","星期二","星期三","星期四","星期五","星期六"};
       Calendar canlendar = Calendar.getInstance(); 
       canlendar.set(year, month-1, day);
       int week = canlendar.get(Calendar.DAY_OF_WEEK)-1;
       System.out.println(weeks[week]);
    }
}
//实现阶乘
class mul{
    void muls(int n){
        int i = 1;
        int sum = 1;
        do 
        {
            sum *= i;
            i++;
        }while(i <= n);
        System.out.println(n+"的阶乘为:"+sum);
    }
}
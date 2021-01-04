import com.sun.xml.internal.ws.api.model.wsdl.WSDLOutput;

import java.util.Random;
import java.util.Scanner;

//步骤 随机生成数字==》用户选择难度0/1/2/default0==》读取用户输入==》比较==>循环/退出
//0 bound:10 10次 / 1 bound:100  7次 / 2 bound:1000 5次
public class GuessNum {
    public static void main(String[] args) {
        int bound=0;
        int guessCount=0;

        Scanner sca = new Scanner(System.in);//用户输入
        System.out.println("请输入难度：");

        int level=sca.nextInt();
        switch (level){
            case 0:
                bound=10;
                guessCount=10;
                break;
            case 1:
                bound=100;
                guessCount=7;
                break;
            case 2:
                bound=1000;
                guessCount=5;
                break;
            default:
                System.out.println("输入有误，请重新输入！");
                break;
        }
        Random rnd = new Random();
        int r = rnd.nextInt(bound);//边界100 得到随机数范围[0,99]

        System.out.println("DEBUG"+r);
        int count=0;
        while (sca.hasNext()&&(count<guessCount)) {                  //判断
            int n = sca.nextInt();
            if (n == r) {
                System.out.println("猜对了！恭喜");
                break;                           //两个退出条件
            } else if (n < r) {
                System.out.println("猜小了");
            } else {
                System.out.println("猜大了");
            }
            count++;
            }
        System.out.println("奖励一朵小红花");
    }
}
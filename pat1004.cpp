/*
 1004. 成绩排名 (20)
 
 时间限制
 400 ms
 内存限制
 65536 kB
 代码长度限制
 8000 B
 判题程序
 Standard
 作者
 CHEN, Yue
 读入n名学生的姓名、学号、成绩，分别输出成绩最高和成绩最低学生的姓名和学号。
 
 输入格式：每个测试输入包含1个测试用例，格式为
 
 第1行：正整数n
 第2行：第1个学生的姓名 学号 成绩
 第3行：第2个学生的姓名 学号 成绩
 ... ... ...
 第n+1行：第n个学生的姓名 学号 成绩
 其中姓名和学号均为不超过10个字符的字符串，成绩为0到100之间的一个整数，这里保证在一组测试用例中没有两个学生的成绩是相同的。
 输出格式：对每个测试用例输出2行，第1行是成绩最高学生的姓名和学号，第2行是成绩最低学生的姓名和学号，字符串间有1空格。
 
 输入样例：
 3
 Joe Math990112 89
 Mike CS991301 100
 Mary EE990830 95
 输出样例：
 Mike CS991301
 Joe Math990112
 */

#include <iostream>
#include <string>
using namespace std;

struct StudentGrade{
    string name;
    string studentID;
    int score;
    
};
int main(){
    int n;
    cin>>n;
    StudentGrade max,min,temp;
    max.score=0;min.score=100;
    for(int i=0;i<n;i++){
        cin>>temp.name>>temp.studentID>>temp.score;
        if(max.score<temp.score)max=temp;
        if(min.score>temp.score)min=temp;
    }
    cout<<max.name<<" "<<max.studentID<<endl;
    cout<<min.name<<" "<<min.studentID<<endl;
    return 0;
}
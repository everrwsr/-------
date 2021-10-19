//��׺����ʽת��׺

#include<iostream>
#include<string>
#include<stack>

using namespace std;

int prio(char op) {                 //����������ȼ�����
    int priority;
    if (op == '*' || op == '/')
        priority = 2;
    if (op == '+' || op == '-')
        priority = 1;
    if (op == '(')
        priority = 0;
    return priority;
}
bool Trans(string &str,string &str1) {   //���ô���
    stack<char> s;                   //����һ��char���͵�ջs
    int i;
    for (i = 0; i<str.size(); i++) {
        if (str[i] >= '0' && str[i] <= '9') {    //��������֣�ֱ����ջ
            str1+=str[i];
        }
        else {                        //����������
            if (s.empty())            //ջ������վ
                s.push(str[i]);
            else if (str[i] == '(')   //��������ջ
                s.push(str[i]);
            else if (str[i] == ')') {  //����������ţ�ֻҪջ�����������ţ��͵��������
                while (s.top() != '(') {  
                    str1+= s.top();
                    s.pop();
                }
                s.pop();                 //���������ţ��������
            }
            else {
                while (prio(str[i]) <= prio(s.top())) { //ջ�����ȼ����ڵ��ڵ�ǰ������������
                    str1+= s.top();
                    s.pop();
                    if (s.empty())      //ջΪ�գ�ֹͣ
                        break;
                }
                s.push(str[i]);   //�ѵ�ǰ�������ջ
            }
        }
    }
    while (!s.empty()) {      //������ջ���գ��򵯳�����Ԫ�ز����
        str1+= s.top();
        s.pop();
    }
    return true;
}
int main() {                //������
    string infix;
    string postfix;
    cout << "��������׺����ʽ��" << infix << endl;
    cin >> infix;
    Trans(infix,postfix);
    cout << "��׺����ʽΪ��" << postfix << endl;
    return 1;
}
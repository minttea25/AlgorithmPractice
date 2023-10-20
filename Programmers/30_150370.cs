// 개인정보 수집 유효기간
// https://school.programmers.co.kr/learn/courses/30/lessons/150370
// 2023 KAKAO BLIND RECRUITMENT

using System;
using System.Collections;
using System.Collections.Generic;

public class Solution {
    const int MAX_MONTH = 12;

    const char ZERO = '0';
    
    public int[] solution(string today, string[] terms, string[] privacies) {
        List<int> answer = new List<int>();
        Date today_date = new Date(today);
        Dictionary<char, int> periods = new Dictionary<char, int>();
        
        foreach(var t in terms) {
            if (t.Length > 4) periods.Add(t[0],  100);
            else if (t.Length > 3) periods.Add(t[0],  (t[2] - ZERO) * 10 + (t[3] - ZERO));
            else periods.Add(t[0],  t[2] - ZERO);
        }
        
        int i=1;
        foreach(var p in privacies) {
            Date elapsed = new Date(p);
            elapsed.AddMonth(periods[p[11]]);
            if (elapsed.IsPassed(today_date) == false) {
                answer.Add(i);
            }
            i++;
        }
        
        return answer.ToArray();
    }
    
    class Date {
        public int y;
        public int m;
        public int d;
        public int Value {
            get {
                return y * 10000 + m * 100 + d;
            }
        }
        
        public Date(string date) {
            y = (date[2] - ZERO) * 10 + (date[3] - ZERO);
            m = (date[5] - ZERO) * 10 + (date[6] - ZERO);
            d = (date[8] - ZERO) * 10 + (date[9] - ZERO);
        }
    
        public void AddMonth(int value) {    
            y += value / MAX_MONTH;
            m += value % MAX_MONTH;
            if (m > MAX_MONTH) {
                m -= MAX_MONTH;
                y += 1;
            }
        }
    
        public bool IsPassed(Date today) {
            Console.WriteLine(Value);
            return today.Value < Value;
        }
    }
}
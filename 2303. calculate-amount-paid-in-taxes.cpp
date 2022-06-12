class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double tax = 0;
        int n = brackets.size();
        if(income > brackets[0][0]) tax += (double) brackets[0][0]*brackets[0][1]/100;
        else 
            tax += (double) income*brackets[0][1]/100;
        //cout<<"haha"<<tax<<endl;
        income -= brackets[0][0];
        for(int i = 1; i < n;i++){
            int earn  = brackets[i][0] - brackets[i-1][0];
            if(income <= 0) return tax;
            if(income >= earn){
                tax += (double) earn * brackets[i][1]/100;
                
           } else 
                tax += (double)income*brackets[i][1]/100;
            income -= earn;
            //cout<<tax<<"--"<<income<<endl;
        }
        return tax;
    }
};

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if(bills[0] == 10 || bills[0] == 20) return false;
        int n = bills.size();
        int fiveDollBill =0;
        int tenDollBill =0;

        for(int i =0; i<n; i++){

            if(bills[i] == 5)fiveDollBill++;
            else if(bills[i]== 10){
                if(fiveDollBill == 0)return false;
                else{
                    fiveDollBill --;
                    tenDollBill++;
                }
            }else{
               

                if(tenDollBill == 0){
                    if(fiveDollBill<3)return false;
                    else{
                        fiveDollBill = fiveDollBill-3;
                    }
                }else{
                    if(fiveDollBill == 0)return false;
                    else{
                        fiveDollBill--;
                        tenDollBill--;
                    }
                }

                

            }
        }

        return true;


        
    }
};

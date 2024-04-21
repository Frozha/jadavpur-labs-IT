#include<iostream>
#include<cmath>
using namespace std;


class polynomial{
    public:
        polynomial(int s) : poly{new element[s]},poly_size{s} {};

        int size(){return poly_size;}


        void display(){
            printf("%.2lfx^%d ",poly[0].coeff,poly[0].exponent);
            for(int i=1;i<poly_size;i++){
                if(!(poly[i].exponent==0&&poly[i].coeff==0)){
                    printf("+ %.2lfx^%d ",poly[i].coeff,poly[i].exponent);  
                }  
            }
            cout<<endl<<endl;
        }

        void init(){
            for(int i=0;i<poly_size;i++){
                printf("Coefficient of %d term - ",i+1);
                cin>>poly[i].coeff;
                printf("Exponent of %d term - ",i+1);
                cin>>poly[i].exponent;
                
            }
            cout<<endl;
            display();
        }

        polynomial sum(polynomial p1, polynomial p2){
            polynomial sum(p1.size()+p2.size());
            int current_tail_index = p1.size()-1;
            int exponent_overlap;
            for(int i=0;i<p1.size();i++){
                sum.poly[i].exponent = p1.poly[i].exponent;
                sum.poly[i].coeff = p1.poly[i].coeff;
            }
            for(int j=0;j<p2.size();j++){
                exponent_overlap=0;
                for(int k=0;k<=current_tail_index;k++){
                    if(sum.poly[k].exponent==p2.poly[j].exponent){
                        exponent_overlap=1;
                        sum.poly[k].coeff+=p2.poly[j].coeff;
                        break;
                    }
                }
                if(exponent_overlap==0){
                    current_tail_index++;
                    sum.poly[current_tail_index].coeff=p2.poly[j].coeff;
                    sum.poly[current_tail_index].exponent = p2.poly[j].exponent;
                }
            }
            polynomial final_sum(current_tail_index+1);
            for(int k =0;k<=current_tail_index;k++){
                final_sum.poly[k].coeff=sum.poly[k].coeff;
                final_sum.poly[k].exponent =sum.poly[k].exponent;
            }
            return final_sum;
        }

        double eval(double x){
            double sum=0;
            for(int i=0;i<poly_size;i++){
                sum+=poly[i].coeff*pow(x,(double)poly[i].exponent);
            }
            return sum;
        }

        polynomial product(polynomial p1,polynomial p2){
            polynomial prod(p1.size()*p2.size());
            int tail_index=0;
            for(int i=0;i<p1.size();i++){
                for(int j=0;j<p2.size();j++){
                    prod.poly[tail_index].coeff = p1.poly[i].coeff*p2.poly[j].coeff;
                    prod.poly[tail_index].exponent = p1.poly[i].exponent + p2.poly[j].exponent;
                    tail_index++;
                }
            }
            prod.display();
            for(int k1=0;k1<prod.size();k1++){
                for(int k2=k1+1;k2<prod.size();k2++){
                    if(prod.poly[k1].exponent==prod.poly[k2].exponent){
                        prod.poly[k1].coeff+=prod.poly[k2].coeff;
                        prod.poly[k2].coeff=0;
                        prod.poly[k2].exponent =0;
                    }
                }
            }
            return prod;
        }

        polynomial make_exponent_unique(polynomial p1);

    private:
        struct element{
            double coeff;
            int exponent;
        };
        element* poly;
        int poly_size;


};

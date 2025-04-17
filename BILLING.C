#include<stdio.h>
#include<conio.h>
#include<string.h>
int num,a,b = 0,c = 0,e,f = 0,m,stock,m1 = 2;
char searchmedicine[20],choice,choice1;
struct details{
	int price,quantity;
	char name[20],brand[20],expirydate[10];
};
struct details medicine[100],billing[100];
void billings(){
	if(e>0){
		float totalamount = 0.0;
		printf("\n------------------------------");
		printf("\n         S S MEDICALS         ");
		printf("\n------------------------------");
		printf("\n periyar nagar madakulam mdu-03");
		printf("\nMedicineName\tMedicineBrand\tMediceneQuantity\tExpiryDate\tPrice\tItemTotal");
		f = 0;
		while(f<e){
			float itemtotal = billing[f].quantity * billing[f].price;
			totalamount += itemtotal;
			printf("\n %s\t\t%s\t\t%d\t%s\t%d\t%f",billing[f].name,billing[f].brand,billing[f].quantity,billing[f].expirydate,billing[f].price,itemtotal);
			f++;
		}
		printf("\n--------------------------------------");
		printf("\n    TOTAL  AMOUNT $   %f",totalamount);
		printf("\n--------------------------------------");
		printf("\n#Thank You For Choosing Our Shop");
	}
}
void menu(){
	printf("Welcome To The Medical Shop Billing System\n");
	do{
		printf("========================================");
		printf("\n\t\tMENU");
		printf("\n========================================");

		printf("\n1.Add Medicene Details");
		printf("\n2.View Medicene Details");
		printf("\n3.View Single Medicene Details");
		printf("\n4.Billings");
		printf("\n5.Exit");

		printf("\nEnter your choice\t:\t");
		scanf("%d",&num);


		if(num==1){
			printf("\n************************");
			printf("\n  Add Medicine Details");
			printf("\n************************");
			printf("\n\Medicine Name\tBrand Name\tMedicine Quantity\tExpiry Date\tPrice\n");
			scanf("%s%s%d%s%d",&medicine[b].name,&medicine[b].brand,&medicine[b].quantity,&medicine[b].expirydate,&medicine[b].price);
			if(medicine[b].price<0){
				m1 = 2;
				printf("\ninvalid price");
				while(m1>0){
					printf("\n\n please enter valid price");
					scanf("%d",&medicine[b].price);
					if(medicine[b].price>0){
						break;
					}
					m1--;
				}
			}
			b++;
			printf("\nYou Added The Medicines Successfully");
		}else if(num==2){
			if(b==0){
				printf("\nPlease Add Medicines");
			}else{
				c = 0;
				printf("\n~~~~~~~~~~~~~~~~~~~~~~~~");
				printf("\n  View Medicene Detail");
				printf("\n~~~~~~~~~~~~~~~~~~~~~~~~");
				printf("\nMedicine Name\t Medicine Brand\t Medicine Quantity\t Expiry Date\t Price");
				while(c<b){
					printf("\n%s\t%s\t\t%d\t\t\t%s\t\t%d",medicine[c].name,medicine[c].brand,medicine[c].quantity,medicine[c].expirydate,medicine[c].price);
					c++;
				}
			}
		}else if(num==3){
			if(b==0){
				printf("\nPlease Add Medicines");
			}else{
				printf("\n********************************");
				printf("\n  View Single Medicine Details");
				printf("\n********************************");
				c = 0;
				printf("\nEnter medicine name\t:\t");
				scanf("%s",&searchmedicine);
				printf("\nMedicine Brand\t  Medicine Quantity\t  Expiry Date\t  Price");
				while(c<b){
					if(strcmp(searchmedicine,medicine[c].name)==0){
					printf("\n%s\t\t%d\t\t\t%s\t\t\t%d",medicine[c].brand,medicine[c].quantity,medicine[c].expirydate,medicine[c].price);
					break;
				}
				c++;
			}
		 }
		}else if(num==4){
			if(b==0){
				printf("\nPlease Add Medicines");
			}else{
				printf("\n----------------------");
				printf("\n   Generating Bills");
				printf("\n----------------------");
				e = 0;
				f = 0;
				do{
					c = 0;
					printf("\nMedicines You Need:-");
					scanf("%s",&billing[f].name);
					while(c<b){
						if(strcmp(billing[f].name,medicine[c].name)==0){
							printf("\nHow Much Quantity You Needed:-");
							scanf("%d",&billing[f].quantity);
							if(medicine[f].quantity<billing[f].quantity){
								printf("\nYour Required Stock Is Not Available");
							}else{
								strcpy(billing[f].brand,medicine[c].brand);
								medicine[f].quantity-=billing[f].quantity;
								strcpy(billing[f].expirydate,medicine[c].expirydate);
								billing[f].price=medicine[c].price;
								e++;
								f++;
							}
						}
						c++;
					}
				printf("\nDo You Want To Add Another Medicines?y/n\n");
				fflush(stdin);
				scanf("%c",&choice);

			}while(choice=='y');

			billings();
		}
		}else if(num==5){
			printf("\nPress Any Key To Exit");
			getch();
			exit(0);
		}else{
			printf("Sorry! Your Choice Is Not Found Please Try Again");
		}
		printf("\n\n Do You Want To Continue\t:\ty/n\n");
		fflush(stdin);
		scanf("%c",&choice1);
		clrscr();
	}while(choice1=='y');
}
void main(){
	clrscr();
	menu();
	getch();
}

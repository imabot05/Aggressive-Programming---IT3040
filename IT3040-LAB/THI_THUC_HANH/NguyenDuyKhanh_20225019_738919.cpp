#include<bits/stdc++.h>
using namespace std;

struct DaThuc{
	string TenDaThuc;
	int bac;
	double x;
	int heso[10];
	double cal(){
		double sum = 0;
		for (int i = bac; i >= 0; i--){
			sum += heso[i]*pow(x,i);
		}
		return sum;
	}
};
int main(){
	int n;
	cout<<"2023.2-Tuan 41-Thu 6-Kip 6h45"<<endl;
	cout<<"Nguyen Duy Khanh - 20225019 - 738919"<<endl;
	cout<<"Nhap so luong da thuc: ";
	cin>>n;
	while(n <= 0){
		cout<<"So luong da thuc khong thoa man, nhap lai!"<<endl;
		cout<<"Nhap so luong da thuc: ";
		cin>>n;
	}
	vector<DaThuc> listDaThuc;
	while(true){
	cout<<"*********************************"<<endl;
		cout<<"2023.2-Tuan 41-Thu 6-Kip 6h45"<<endl;
		cout<<"Nguyen Duy Khanh - 20225019 - 738919"<<endl;
		cout<<"** CHUONG TRINH QUAN LY CAC DA THUC"<<endl;
		cout<<"** 1. Nhap cac da thuc, gia tri x"<<endl;
		cout<<"** 2. In danh sach da thuc, va gia tri"<<endl;
		cout<<"** 0. Thoat"<<endl;
		cout<<"*********************************"<<endl;
		cout<<"**\t"<<"Nhap lua chon cua ban"<<"\t"<<endl;
		int option;
		cin>>option;
		if (option == 1){
			cout<<"Ban da chon nhap danh sach da thuc"<<endl;
			for (int i = 0; i < n ; i++){
				cout<<"Nhap da thuc thu "<<i + 1<<endl;
				cout<<"2023.2-Tuan 41-Thu 6-Kip 6h45"<<endl;
				cout<<"Nguyen Duy Khanh - 20225019 - 738919"<<endl;
				DaThuc dt;
				cout<<"Nhap ten da thuc: ";
				cin>>dt.TenDaThuc;
				cout<<"\nNhap bac: ";
				cin>>dt.bac;
				cout<<"\nNhap x: ";
				cin>>dt.x;
				cout<<"\n";
				for (int i = dt.bac; i >= 0; i--){
					cout<<"\nHe so bac ";
					cout<<i<<" :";
					cin>>dt.heso[i];
				}
				listDaThuc.push_back(dt);
			}
		}
		else if (option == 2){
			cout<<"Ban da chon xuat ra DS da thuc, Gia tri da thuc!"<<endl;
			cout<<"2023-2-Tuan 41-Thu 6-Kip 6h45"<<endl;
			cout<<"Nguyen Duy Khanh - 20225019 - 738919"<<endl;
			cout<<"_____________________________________"<<endl;
			for (int i = 0; i < listDaThuc.size(); i++){
				cout<<"Da thuc "<<listDaThuc[i].TenDaThuc<<"(x)"<<" =\t";
				for (int j = listDaThuc[i].bac; j >= 0; j--){
					if (j == 0){
						if (listDaThuc[i].heso[j] > 0){
							cout<<" +"<<listDaThuc[i].heso[j];	
						}
						else {
							cout<<" "<<listDaThuc[i].heso[j];
						}
					}
					else {
					if (listDaThuc[i].heso[j] > 0){
						if (j == listDaThuc[i].bac){
							cout<<listDaThuc[i].heso[j]<<"*x^"<<j;
						}
						else {
							cout<<" + "<<listDaThuc[i].heso[j]<<"*x^"<<j;
						}
					}
					else if (listDaThuc[i].heso[j] < 0){
						cout<<" "<<listDaThuc[i].heso[j]<<"*x^"<<j;
					}
				}
				}
				cout<<endl;
				cout<<"Gia tri da thuc: "<<listDaThuc[i].TenDaThuc<<" ("<<listDaThuc[i].x<<") = "<<fixed<<setprecision(2)<<listDaThuc[i].cal()<<endl;
			}
			cout<<"_____________________________________"<<endl;
			cout<<"Bam phim bat ky de tiep tuc!"<<endl;
			string k;
			cin>>k;
			cout<<endl;
		}
		else if (option == 0){
			cout<<"Ban da thoat khoi chuong trinh!";
			break;
		}
	}
	}


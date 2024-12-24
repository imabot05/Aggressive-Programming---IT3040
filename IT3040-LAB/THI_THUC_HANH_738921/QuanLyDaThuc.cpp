#include<bits/stdc++.h>

using namespace std;

struct DaThuc{
    string tenDaThuc;
    int bac;
    double x;
    int heSo[10];
    double cal(){
        double sum = 0;
        for (int i = bac; i >= 0; i--){
            sum += heSo[i] * pow(x, i);
        }
        return sum;
    }
};

int main(int argc, const char **argv){
    int n;
    cout << "2023.2 - Tuan 41 - Thu 6 - Kip 6h45" << endl;
    cout<<"Nguyen Duy Khanh - 20225019 - 738919"<<endl;
	cout<<"Nhap so luong da thuc: ";
	cin >> n;
	while (n <= 0){
        cout<<"So luong da thuc khong thoa man, nhap lai!"<<endl;
		cout<<"Nhap so luong da thuc: ";
		cin>>n;
	}

	vector<DaThuc> danhSachDaThuc;
	while (true) {
        cout << "*************************" << endl;
        cout<<"2023.2-Tuan 41-Thu 6-Kip 6h45"<<endl;
		cout<<"Nguyen Duy Khanh - 20225019 - 738919"<<endl;
		cout<<"** CHUONG TRINH QUAN LY CAC DA THUC"<<endl;
		cout<<"** 1. Nhap cac da thuc, gia tri x"<<endl;
		cout<<"** 2. In danh sach da thuc, va gia tri"<<endl;
		cout<<"** 0. Thoat"<<endl;
		cout<<"*********************************"<<endl;
		cout<<"**\t"<<"Nhap lua chon cua ban"<<"\t"<<endl;
		int option;
		cin >> option;
		if (option == 1){
            cout << "Ban da chon nhap danh sach da thuc" << endl;
            for (int i = 0; i < n; i++){
                cout << "Nhap da thuc thu " << i + 1 << endl;
                cout<<"2023.2-Tuan 41-Thu 6-Kip 6h45"<<endl;
				cout<<"Nguyen Duy Khanh - 20225019 - 738919"<<endl;
				DaThuc daThuc;
				cout << setw(10) << "Nhap ten da thuc: ";
				cin >> daThuc.tenDaThuc;
				cout << endl;
				cout << setw(10) << "Nhap bac: ";
				cin >> daThuc.bac;
				cout << endl;
				cout << setw(10) << "Nhap x: ";
				cin >> daThuc.x;
				cout << endl;
				for (int i = daThuc.bac; i >= 0; i--){
                    cout << "\nHe so bac: ";
                    cout << i << " : ";
                    cin >> daThuc.heSo[i];
				}
				danhSachDaThuc.push_back(daThuc);
            }
		} else if (option == 2){
            cout<<"Ban da chon xuat ra DS da thuc, Gia tri da thuc!"<<endl;
			cout<<"2023-2-Tuan 41-Thu 6-Kip 6h45"<<endl;
			cout<<"Nguyen Duy Khanh - 20225019 - 738919"<<endl;
			cout<<"_____________________________________"<<endl;
			for (int i = 0; i < danhSachDaThuc.size(); i++){
                cout << "Da thuc " << danhSachDaThuc[i].tenDaThuc << "(x)" << " =\t";
                for (int j = danhSachDaThuc[i].bac; j >= 0; j--){
                    if (j == 0){
                        if (danhSachDaThuc[i].heSo[j] > 0){
                            cout << " + " << danhSachDaThuc[i].heSo[j];
                        } else {
                            cout << " " << danhSachDaThuc[i].heSo[j];
                        }
                    } else if (j == 1){
                        if (danhSachDaThuc[i].heSo[j] > 0){
                            cout << " + " << danhSachDaThuc[i].heSo[j] << "*x";
                        } else {
                            cout << " " << danhSachDaThuc[i].heSo[j] << "*x";
                        }
                    } else {
                        if (danhSachDaThuc[i].heSo[j] > 0){
                            if (j == danhSachDaThuc[i].bac){
                                cout << danhSachDaThuc[i].heSo[j] << "*x^" << j;
                            } else {
                                cout << " + " << danhSachDaThuc[i].heSo[j] << "*x^" << j;
                            }
                        } else if (danhSachDaThuc[i].heSo[j] < 0){
                            cout << " " << danhSachDaThuc[i].heSo[j] << "x^" << j;
                        }
                    }
                }
                cout << endl;
                cout<<"Gia tri da thuc: " << danhSachDaThuc[i].tenDaThuc<< " (" << danhSachDaThuc[i].x << ") = " << fixed << setprecision(2) << danhSachDaThuc[i].cal()<<endl;
			}
			cout << "_______________________" << endl;
			cout << "Bam phim bat ky de tiep tuc";
			string k;
			cin >> k;
			cout << endl;
		} else if (option == 0){
            cout << "Ban da thoat khoi chuong trinh!";
            break;
		}
	}
    return 0;
}

2023.2 - Tuan 41 - Thu 6 - Kip 6h45
Nguyen Duy Khanh - 20225019 - 738919
Nhap so luong da thuc: 2
*************************
2023.2-Tuan 41-Thu 6-Kip 6h45
Nguyen Duy Khanh - 20225019 - 738919
** CHUONG TRINH QUAN LY CAC DA THUC
** 1. Nhap cac da thuc, gia tri x
** 2. In danh sach da thuc, va gia tri
** 0. Thoat
*********************************
**      Nhap lua chon cua ban
1
Ban da chon nhap danh sach da thuc
Nhap da thuc thu 1
2023.2-Tuan 41-Thu 6-Kip 6h45
Nguyen Duy Khanh - 20225019 - 738919
Nhap ten da thuc: F

Nhap bac: 5

  Nhap x: -3


He so bac: 5 : 2

He so bac: 4 : -4

He so bac: 3 : 5

He so bac: 2 : 0

He so bac: 1 : -10

He so bac: 0 : 23
Nhap da thuc thu 2
2023.2-Tuan 41-Thu 6-Kip 6h45
Nguyen Duy Khanh - 20225019 - 738919
Nhap ten da thuc: G

Nhap bac: 4

  Nhap x: 2


He so bac: 4 : 5

He so bac: 3 : -6

He so bac: 2 : 3

He so bac: 1 : 19

He so bac: 0 : -18
*************************
2023.2-Tuan 41-Thu 6-Kip 6h45
Nguyen Duy Khanh - 20225019 - 738919
** CHUONG TRINH QUAN LY CAC DA THUC
** 1. Nhap cac da thuc, gia tri x
** 2. In danh sach da thuc, va gia tri
** 0. Thoat
*********************************
**      Nhap lua chon cua ban
2
Ban da chon xuat ra DS da thuc, Gia tri da thuc!
2023-2-Tuan 41-Thu 6-Kip 6h45
Nguyen Duy Khanh - 20225019 - 738919
_____________________________________
Da thuc F(x) =  2*x^5 -4x^4 + 5*x^3 -10*x + 23
Gia tri da thuc: F (-3) = -892.00
Da thuc G(x) =  5*x^4 -6x^3 + 3*x^2 + 19*x -18
Gia tri da thuc: G (2.00) = 64.00
_______________________
Bam phim bat ky de tiep tuc


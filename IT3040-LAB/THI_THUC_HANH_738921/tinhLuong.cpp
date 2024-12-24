#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<climits>

using namespace std;

struct NhanVien{
	string maNV;
	string hoTenNV;
	int namSinh;
	double heSoLuong;
	int luongToiThieu;
    string chucDanh;
};

struct PhongBan{
	string tenPhongBan;
    string diaChi;
    int soLuongNV;
    int luongToiThieu;
    vector<NhanVien> danhSachNhanVien;
};

double tinhLuong(NhanVien nhanVien){
	double luong = nhanVien.heSoLuong * nhanVien.luongToiThieu;
	return luong;
}

int PhuCapCongViec(NhanVien nhanVien){
	if (nhanVien.chucDanh == "GVCC"){
		return 2000;
	}
	else if (nhanVien.chucDanh == "GVC"){
		return 1500;
	}
	else if (nhanVien.chucDanh == "GV"){
		return 1000;
	}
	else if (nhanVien.chucDanh == "CBKT"){
		return 750;
	}
	else if (nhanVien.chucDanh == "CBHC"){
		return 500;
	}
	return 0;
}

int tongLuong(NhanVien nhanVien){
	if (nhanVien.chucDanh == "GVCC"){
		return tinhLuong(nhanVien) + 2000;
	}
	else if (nhanVien.chucDanh == "GVC"){
		return tinhLuong(nhanVien) + 1500;
	}
	else if (nhanVien.chucDanh == "GV"){
		return tinhLuong(nhanVien) + 1000;
	}
	else if (nhanVien.chucDanh == "CBKT"){
		return tinhLuong(nhanVien) + 750;
	}
	else if (nhanVien.chucDanh == "CBHC"){
		return tinhLuong(nhanVien) + 500;
	}
	return tinhLuong(nhanVien);
}

int tongLuongPhongBan(PhongBan phongBan){
	int rs = 0;
	for (int i = 0; i < phongBan.soLuongNV; i++){
		NhanVien nhanVien = phongBan.danhSachNhanVien[i];
		rs += tongLuong(nhanVien);
	}
	return rs;
}

int main(int argc, const char **argv){
	vector<PhongBan> danhSachPhongBan;
	cout << "Kip 1 - Thu 6 - Tuan 40 - 738921" << endl << "20241 - Nguyen_Duy_Khanh - 20225019" << endl << "** CHUONG TRINH QUAN LY Phong Ban - Nhan Vien **"<< endl << "** 1. Nhap cac Phong ban        **"<< endl << "** 2. In ket qua ds phong ban va Nhan Vien **" << endl << "0. Thoat"<< endl << "********************************************"<< endl << "** Nhap lua chon cua ban:                   **"<< endl;
    string s;
	int n;
	while (cin >> s){
		if (s == "1"){
			cout << "Nhap so luong phong ban: " << endl;
			cin >> n;
			for (int i = 1; i <= n; i++){
				PhongBan phongBan;
				cout << "Nhap thong tin phong ban thu " << i << ":" << endl << "    Ten Phong Ban:";
				cin >> phongBan.tenPhongBan;
				cout << "\nDia chi: ";
				cin >> phongBan.diaChi;
				cout << "\nLuong toi thieu: ";
				cin >> phongBan.luongToiThieu;
				cout << endl;
				cout << "So Nhan Vien: ";
				cin >> phongBan.soLuongNV;
				for (int j = 0; j < phongBan.soLuongNV; j++){
					NhanVien nhanVien;
					cout << setw(10) << "Ma Nhan Vien: ";
                    cin >> nhanVien.maNV;
                    cout << endl;
                    cout << setw(10) << "Ho ten Nhan Vien: ";
                    cin.ignore();
                    getline(cin, nhanVien.hoTenNV);
                    cout << endl;
                    cout << setw(10) << "Nhap Nam Sinh: ";
                    cin >> nhanVien.namSinh;
                    cout << endl;
                    cout << setw(10) << "Nhap HS Luong: ";
                    cin >> nhanVien.heSoLuong;
                    cout << endl;
                    cout << setw(10) << "Nhap Chuc Danh: ";
                    cin >> nhanVien.chucDanh;
                    cout << endl;
                    nhanVien.luongToiThieu = phongBan.luongToiThieu;
                    phongBan.danhSachNhanVien.push_back(nhanVien);
				}
				danhSachPhongBan.push_back(phongBan);
			}
            cout << "Ban da nhap thanh cong!" << endl << "Bam phim bat ky de tiep tuc" << endl;
		}
		else if (s == "2"){
            cout << "Ban da chon xuat DS Phong ban !" << endl;
            for (int i = 0; i < danhSachPhongBan.size(); i++){
                PhongBan phongBan = danhSachPhongBan[i];
                cout << setw(10) << "Ten phong ban: " << phongBan.tenPhongBan << endl;
                cout << setw(10) << "Luong toi thieu: " << phongBan.luongToiThieu << endl;
                cout << setw(10) << "Tong luong PB: " << tongLuongPhongBan(phongBan) << endl;
                cout << setw(10) << "Tong CD Phi: " << 0.01 * tongLuongPhongBan(phongBan) << endl;
                for (int j = 0; j < phongBan.soLuongNV; j++){
                    NhanVien nhanVien = phongBan.danhSachNhanVien[j];
                    cout << setw(10) << "MaNV" << setw(10) << "Ho ten NV"  << setw(10) << "Chucdanh" << setw(10) << "PCCV" << setw(10) << "HeSoL" << setw(10) << "Luong" << setw(10) << "CDP" << setw(10) << "Con Nhan"<< endl;
                    cout << setw(10) << nhanVien.maNV << setw(10) << nhanVien.hoTenNV << setw(10) << nhanVien.chucDanh << setw(10) << PhuCapCongViec(nhanVien) << setw(10) << nhanVien.heSoLuong << setw(10) << tongLuong(nhanVien) << setw(10) << 0.01 * tongLuong(nhanVien) << setw(10) << (double)0.99 * tongLuong(nhanVien) << endl;
                }
            }
		}
		else if ( s == "0"){
			cout << "Ban da chon thoat chuong trinh !";
			break;
		}
	}
    return 0;
}






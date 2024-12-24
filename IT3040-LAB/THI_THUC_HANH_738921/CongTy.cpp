#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

struct NhanVien{
    string maNV;
    string hoTen;
    int namSinh;
    double heSoLuong;
    string chucDanh;

    int tinhLuong(int luongToiThieu){
        return round(heSoLuong * luongToiThieu);
    }

    int phuCapCongViec(){
        if (chucDanh == "GVCC"){
            return 2000;
        } else if (chucDanh == "GVC"){
            return 1500;
        } else if (chucDanh == "GV"){
            return 1000;
        } else if (chucDanh == "CBKT"){
            return 750;
        } else if (chucDanh == "CBHC"){
            return 500;
        } else return 0;
    }

    int tongLuong(int luongToiThieu){
        return tinhLuong(luongToiThieu) + phuCapCongViec();
    }

    double CPD(int luongToiThieu){
        return tongLuong(luongToiThieu) * 0.01;
    }

    double thucNhan(int luongToiThieu){
        return tongLuong(luongToiThieu) - CPD(luongToiThieu);
    }
};

struct PhongBan{
    string ten;
    string diaChi;
    int soLuongNhanVien;
    int luongToiThieu;
    vector<NhanVien> danhSachNhanVien;
};

double tongLuong(PhongBan phongBan){
    double result = 0;
    for (int i = 0; i < phongBan.danhSachNhanVien.size(); i++){
        NhanVien nhanVien = phongBan.danhSachNhanVien[i];
        double luong = nhanVien.tongLuong(phongBan.luongToiThieu);
        result += luong;
    }
    return result;
}

double tongCPD(PhongBan phongBan){
    double result = 0;
    for (int i = 0; i < phongBan.danhSachNhanVien.size(); i++){
        NhanVien nhanVien = phongBan.danhSachNhanVien[i];
        double CPD = nhanVien.CPD(phongBan.luongToiThieu);
        result += CPD;
    }
    return result;
}

int main(int argc, const char **argv){
    vector<PhongBan> danhSachPhongBan;
    cout << "Kip 1 - Thu 6 - Tuan 40 - 738921" << endl << "20241 - Nguyen_Duy_Khanh - 20225019" << endl << "** CHUONG TRINH QUAN LY Phong Ban - Nhan Vien **"<< endl << "** 1. Nhap cac Phong ban        **"<< endl << "** 2. In ket qua ds phong ban va Nhan Vien **" << endl << "0. Thoat"<< endl << "********************************************"<< endl << "** Nhap lua chon cua ban:                   **"<< endl;
    string s;
    int n;
    while (cin >> s){
        if (s == "1"){
            cout << setw(10) << "Nhap so luong phong ban: " << endl;
            cin >> n;
            for (int i = 1; i <= n; i++){
                PhongBan phongBan;
                cout << setw(10) << "Nhap thong tin phong ban thu " << i << ":" << endl;
                cout << setw(10) << "Ten Phong Ban: ";
                cin >> phongBan.ten;
                cout << endl;
                cout << setw(10) << "Dia chi: ";
				cin >> phongBan.diaChi;
				cout << endl;
				cout << setw(10) << "Luong toi thieu: ";
				cin >> phongBan.luongToiThieu;
				cout << endl;
				cout << setw(10) << "So Nhan Vien: ";
				cin >> phongBan.soLuongNhanVien;
				cout << endl;
				for (int j = 0; j < phongBan.soLuongNhanVien; j++){
                    NhanVien nhanVien;
                    cout << setw(10) << "Ma Nhan Vien: ";
                    cin >> nhanVien.maNV;
                    cout << endl;
                    cout << setw(10) << "Ho ten nhan vien: ";
                    cin.ignore();
                    getline(cin, nhanVien.hoTen);
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
                    phongBan.danhSachNhanVien.push_back(nhanVien);
				}
				danhSachPhongBan.push_back(phongBan);
            }
            cout << setw(10) << "Ban da nhap thanh cong!" << endl;
            cout << setw(10) << "Bam phim bat ky de tiep tuc" << endl;
        } else if (s == "2"){
            cout << "Ban da chon xuat DS Phong ban !" << endl;
            for (int i = 0; i < danhSachPhongBan.size(); i++){
                PhongBan phongBan = danhSachPhongBan[i];
                cout << setw(10) << "Ten phong ban: " << phongBan.ten << endl;
                cout << setw(10) << "Luong toi thieu: " << phongBan.luongToiThieu << endl;
                cout << setw(10) << "Tong luong PB: " << tongLuong(phongBan) << endl;
                cout << setw(10) << "Tong CD Phi: " << tongCPD(phongBan) << endl;
                for (int j = 0; j < phongBan.soLuongNhanVien; j++){
                    NhanVien nhanVien = phongBan.danhSachNhanVien[j];
                    cout << setw(10) << "MaNV" << setw(10) << "Ho ten NV"  << setw(20) << "Chucdanh" << setw(10) << "PCCV" << setw(10) << "HeSoL" << setw(10) << "Luong" << setw(10) << "CDP" << setw(10) << "Con Nhan"<< endl;
                    cout << setw(10) << nhanVien.maNV << setw(10) << nhanVien.hoTen << setw(20) << nhanVien.chucDanh << setw(10) << nhanVien.phuCapCongViec() << setw(10) << nhanVien.heSoLuong << setw(10) << nhanVien.tongLuong(phongBan.luongToiThieu) << setw(10) << nhanVien.CPD(phongBan.luongToiThieu) << setw(10) << nhanVien.thucNhan(phongBan.luongToiThieu) << endl;
                }
            }
        }
        else if (s == "0"){
            cout << "Ban da chon thoat chuong trinh !";
			break;
        }
    }
    return 0;
}

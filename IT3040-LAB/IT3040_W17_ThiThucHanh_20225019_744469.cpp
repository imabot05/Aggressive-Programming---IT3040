#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<conio.h>


using namespace std;

struct MonHoc{
	string maMH;
	int soTinChiMH;
	double trongSoCK;
	double diemQT;
	double diemCK;
	double diemMH;
	string ketQuaMH;
};

struct SinhVien{
	string maSV;
	string hoTenSV;
	int soMonHoc;
	vector<MonHoc> danhSachMonHoc;
	double diemCPA;
	string diemChuCPA;
};

void nhapDanhSachMonHoc(vector<MonHoc> &danhSachMonHoc, int soMonHoc){
	for (int i = 0; i < soMonHoc; i++){
		MonHoc monHoc;
		cout << "\nNhap mon hoc thu " << i + 1 << endl;
		cout << "\t" << "Nhap ma MH: ";
		cin >> monHoc.maMH;
		cout << "\t" << "Nhap so tin chi: ";
		cin >> monHoc.soTinChiMH;
		cout << "\t" << "Nhap trong so CK: > 0, < 1: ";
		double trongSo;
		while (true) {
			cin >> trongSo;
			if (trongSo > 0 && trongSo < 1){
				monHoc.trongSoCK = trongSo;
				break;
			} else {
				cout << "Trong so cuoi ki phai trong khoang tu 0 - 1. Vui long nhap lai." << endl;
			}
		}
		cout << "\t" << "Nhap diem QT: ";
		cin >> monHoc.diemQT;
		cout << "\t" << "Nhap diem CK: ";
		cin >> monHoc.diemCK;
		double diemMonHoc;
		diemMonHoc = monHoc.diemQT * (1- monHoc.trongSoCK) + monHoc.diemCK * monHoc.trongSoCK;
		monHoc.diemMH = diemMonHoc;
		if (diemMonHoc >= 9.5){
			monHoc.ketQuaMH = "Xuat sac";
		} else if (diemMonHoc > 8.5){
			monHoc.ketQuaMH = "Gioi";
		} else if (diemMonHoc > 6.5){
			monHoc.ketQuaMH = "Kha";
		} else if (diemMonHoc >= 5){
			monHoc.ketQuaMH = "Trung binh";
		} else if (diemMonHoc < 5){
			monHoc.ketQuaMH = "Yeu";
		}
		danhSachMonHoc[i] = monHoc;
	}
	cout << "Ban da nhap thanh cong!" << endl;   
}

void inDanhSachSinhVien(vector<SinhVien> &danhSachSinhVien){
	for (int i = 0; i < danhSachSinhVien.size(); i++){
		cout << "\n=========================================" << endl;
		cout << "\n========KET QUA HOC TAP SINH VIEN========" << endl;
		SinhVien sinhVien = danhSachSinhVien[i];
		cout << "MaSV: ";
		cout << sinhVien.maSV << endl;
		cout << "TenSV: ";
		cout << sinhVien.hoTenSV << endl;
		cout << "SoMH: ";
		cout << sinhVien.soMonHoc << endl;
		cout << "TT" << setw(15) << "MaMH" << setw(15) << "SoTC" << setw(15) << "T.so" << setw(15) << "D.QT" << setw(15) << "D.CK" << setw(15) << "D.MH" << setw(15) <<"XLoaiMH" << endl;
		vector<MonHoc> danhSachMonHoc = sinhVien.danhSachMonHoc;
		for (int j = 0; j < danhSachMonHoc.size(); j++){
			cout << j + 1 << setw(18) << danhSachMonHoc[j].maMH
				<< setw(13) << danhSachMonHoc[j].soTinChiMH
				<< setw(15) << danhSachMonHoc[j].trongSoCK
				<< setw(15) << danhSachMonHoc[j].diemQT
				<< setw(15) << danhSachMonHoc[j].diemCK
				<< setw(15) << danhSachMonHoc[j].diemMH
				<< setw(15) << danhSachMonHoc[j].ketQuaMH;
			cout << endl;
		}
		cout << "Diem CPA: " << sinhVien.diemCPA << endl;
		cout << "Diem chu: " << sinhVien.diemChuCPA << endl;
		cout << "================================================" << endl;
	}
}

void pressAnyKey(){
	cout << "Bam phim bat ky de tiep tuc!";
	getch();
	system("cls");
}

int main(){
	vector<SinhVien> danhSachSinhVien;
	int soLuongSinhVien;
	cout << "Kip 12h30 - Tuan 17 - Ngay 27/12/2024 " << endl;
	cout << "Kiem tra thuc hanh - Quan ly diem sinh vien" << endl;
	cout << "Nguyen Duy Khanh - 20225019 - 744469 - 20241" << endl;
	cout << "Nhap so luong sinh vien: ";
	cin >> soLuongSinhVien;
	while (soLuongSinhVien <= 0){
		cout << "So luong sinh vien nhap khong hop le. Vui long nhap lai. " << endl;
		cout << "Nhap so luong sinh vien: ";
		cin >> soLuongSinhVien;
	} 
	danhSachSinhVien.resize(soLuongSinhVien);
	while (true) {
		cout << "Kip 12h30 - Tuan 17 - Ngay 27/12/2024" << endl;
		cout << "Nguyen Duy Khanh - 20225019 - 744469 - 20241" << endl;
		cout << "** CHUONG TRINH QUAN LY DIEM SINH VIEN  **" << endl;
		cout << "**1. Nhap cac sinh vien" << setw(20) << "**" <<endl;
		cout << "**2. In Thong tin SV, Ket qua,.." << setw(10) << "**" << endl;
		cout << "**0. Thoat" << setw(20) << "**" << endl;
		cout << "****************************" << endl;
		cout << "**    Nhap lua chon cua ban    **" << endl;
		int choice;
		cin >> choice;
		if (choice == 1){
			cout << "Nguyen Duy Khanh - 20225019 - 744469 - 20241" << endl;
			cout << "Ban da chon nhap danh sach sinh vien!" << endl;
			for (int i = 0; i < soLuongSinhVien; i++){
				SinhVien sinhVien;
				cout << "Nhap thong tin cua sinh vien thu " << i + 1 << ":" << endl;
				cout << " Nhap ma sinh vien: ";
				cin >> sinhVien.maSV;
				cout << endl;
				cout << " Nhap ten SV: ";
				cin.ignore();
				getline(cin, sinhVien.hoTenSV);
				cout << endl;
				cout << "Nhap so mon hoc: ";
				cin >> sinhVien.soMonHoc;
				vector<MonHoc> danhSachMonHoc;
				danhSachMonHoc.resize(sinhVien.soMonHoc);
				nhapDanhSachMonHoc(danhSachMonHoc, sinhVien.soMonHoc);
				sinhVien.danhSachMonHoc = danhSachMonHoc;
				double tongDiem = 0;
				double tongSoTinChi = 0;
				for (int j = 0; j < danhSachMonHoc.size(); j++){
					tongDiem += danhSachMonHoc[j].diemMH * danhSachMonHoc[j].soTinChiMH;
					tongSoTinChi += danhSachMonHoc[j].soTinChiMH;
				}
				double diemCPA = tongDiem / tongSoTinChi;
				sinhVien.diemCPA = diemCPA;
				if (diemCPA >= 9){
					sinhVien.diemChuCPA = "A+";
				} else if (diemCPA >= 8.5){
					sinhVien.diemChuCPA = "A";
				} else if (diemCPA >= 7.5){
					sinhVien.diemChuCPA = "B+";
				} else if (diemCPA >= 6.5){
					sinhVien.diemChuCPA = "B";
				} else if (diemCPA >= 5){
					sinhVien.diemChuCPA = "C";
				} else if (diemCPA >= 4){
					sinhVien.diemChuCPA = "D";
				} else {
					sinhVien.diemChuCPA = "F";
				}
				danhSachSinhVien[i] = sinhVien;
			} 
			cout << "Nguyen Duy Khanh - 20225019 - 744469 - 20241" << endl;
			pressAnyKey();
		} else if (choice == 2){
			cout << "Ban da chon xuat DS sinh vien " << endl;
			cout << "!" << endl;
			inDanhSachSinhVien(danhSachSinhVien);
			cout << "Ban da in danh sach sinh vien thanh cong" << endl;
			pressAnyKey();
		} else if (choice == 0){
			cout << "Nguyen Duy Khanh - 20225019 - 744469 - 20241" << endl;
			cout << "Ban da chon thoat chuonng trinh!" << endl;
			break;
		} else {
			cout << "Nguyen Duy Khanh - 20225019 - 744469 - 20241" << endl;
			cout << "Khong co chuc nang nay!" << endl;
			pressAnyKey();
		}
	}
	return 0;	
}
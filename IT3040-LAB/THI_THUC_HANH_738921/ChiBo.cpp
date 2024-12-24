#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<iomanip>

#define MAXN 101

using namespace std;

struct DangVien{
    int soTheDV;
    string tenDangVien;
    int ngay, thang, nam;
    int namVaoDang;
    string chucVuDang;
    float luong;
    float dangPhi;
    float tienPhuCap;
    float phaiDong;
};

struct ChiBo{
    string tenChiBo;
    string diaChi;
    int soDangVien;
    float tongLuong;
    float tongDangPhiThu;
    float chiBoGiuLai;
    float nopCapTren;
    float tongTroCapChucVu;
    vector<DangVien> danhSachDangVien;
};

void nhapDangVien(DangVien &dangVien){
    cout << "So the: ";
    cin >> dangVien.soTheDV;
    cout << endl;
    cout << "Ten dang vien: ";
    cin.ignore();
    getline(cin, dangVien.tenDangVien);
    cout << endl;
    cout << "Ngay vao dang: ";
    cout << "\tNgay: "; cin >> dangVien.ngay;
    cout << "\tThang: "; cin >> dangVien.thang;
    cout << "\tNam: "; cin >> dangVien.nam;
    cout << endl;
    cout << "Luong: ";
    cin >> dangVien.luong;
    cout << endl;
    cout << "Chuc vu: ";
    cin >> dangVien.chucVuDang;
    dangVien.dangPhi = 0.01 * dangVien.luong;
    string chucVu = dangVien.chucVuDang;
    if (chucVu == "BiThu"){
        dangVien.tienPhuCap = 0.05 * dangVien.luong;
    } else if (chucVu == "PBThu") {
        dangVien.tienPhuCap = 0.025 * dangVien.luong;
    } else if (chucVu == "Uyvien"){
        dangVien.tienPhuCap = 0.015 * dangVien.luong;
    } else {
        dangVien.tienPhuCap = 0;
    }
}

void pressAnyKey(){
    cout << "\n Bam phim bat ky de tiep tuc...";
    getch();
    system("cls");
}

int main(int argc, const char **argv){
    int key;
    vector<ChiBo> danhSachChiBo;
    int n;
    cout << "Nguyen Duy Khanh - 20225019 - 721019 - 20232 - IT3040: \n";
    cout << "Nhap so chi bo: ";
    cin >> n;
    while(true){
        cout << "Nguyen Duc Duy - 20210275 - 727639 - 2022.2 - IT3040: \n";
        cout << "**     CHUONG TRINH QUAN LY CHi BO - DANG VIEN     **\n";
        cout << "********************MENU*****************************\n";
        cout << "**     1. Nhap cac Chi bo                          **\n";
        cout << "**     2. In ket qua ds Chi bo Dang vien           **\n";
        cout << "**     0. Thoat                                    **\n";
        cout << "*****************************************************\n";
        cout << "Nhap lua chon: ";
        cin >> key;

        switch(key){
            case 1:
                cout << "\nBan da chon nhap danh sach cac chi bo";
                cout << endl;
                for (int i = 0; i < n; i++){
                    cout << "Nhap thong tin chi bo thu " << i + 1 << ":" << endl;
                    ChiBo chiBo;
                    cout << "Nhap ten chi bo: ";
                    cin.ignore();
                    getline(cin, chiBo.tenChiBo);
                    cout << endl;
                    cout << "So dang vien: ";
                    cin >> chiBo.soDangVien;
                    cout << endl;
                    cout << "Nhap danh sach dang vien: \n";
                    chiBo.danhSachDangVien.resize(chiBo.soDangVien);
                    for (int i = 0; i < chiBo.soDangVien; i++){
                        cout << "Dang vien thu " << i + 1 << endl;
                        nhapDangVien(chiBo.danhSachDangVien[i]);
                    }
                    chiBo.tongLuong = 0;
                    chiBo.tongDangPhiThu = 0;
                    chiBo.tongTroCapChucVu = 0;
                    for (int i = 0; i < chiBo.soDangVien; i++){
                        chiBo.tongLuong += chiBo.danhSachDangVien[i].luong;
                        chiBo.tongDangPhiThu += chiBo.danhSachDangVien[i].dangPhi;
                        chiBo.tongTroCapChucVu += chiBo.danhSachDangVien[i].tienPhuCap;
                    }
                    chiBo.chiBoGiuLai = 0.7 * chiBo.tongDangPhiThu;
                    chiBo.nopCapTren = 0.3 * chiBo.tongDangPhiThu;
                    danhSachChiBo.push_back(chiBo);
                }
                break;
            case 2:
                cout << "\nBan da chon xuat DS chi bo" << endl;
                float tongLuongCacChiBo = 0;
                float tongDangPhiThuDuoc = 0;
                float nopCapTren = 0;
                for (int i = 0; i < n; i++){
                    tongLuongCacChiBo += danhSachChiBo[i].tongLuong;
                    tongDangPhiThuDuoc += danhSachChiBo[i].tongDangPhiThu;
                    nopCapTren += danhSachChiBo[i].nopCapTren;
                    cout << "-----------------------------------------------------------------------------------------------";
                    cout << "Ten chi bo: " << danhSachChiBo[i].tenChiBo << endl;
                    cout << "So dang vien: " << danhSachChiBo[i].soDangVien << endl;
                    cout << "Tong luong: " << fixed << setprecision(2) << danhSachChiBo[i].tongLuong << endl;
                    cout << "Tong thu dang phi: " << fixed << setprecision(2) << danhSachChiBo[i].tongDangPhiThu << endl;
                    cout << "Tong nop dang phi cap tren: " << fixed << setprecision(2) << danhSachChiBo[i].nopCapTren << endl;
                    cout << "Tong tro cap chuc vu: " << fixed << setprecision(2) << danhSachChiBo[i].tongTroCapChucVu << endl;
                    cout << "Bang bang thu dang phi: " << endl;
                    cout<<left<<setw(10)<<"sothe"
                        <<left<<setw(20)<<"HotenDV"
                        <<left<<setw(15)<<"Ngayvaodang"
                        <<left<<setw(10)<<"Tuoidang"
                        <<left<<setw(10)<<"Chucvu"
                        <<left<<setw(10)<<"Trocap"
                        <<left<<setw(10)<<"Luong"
                        <<left<<setw(10)<<"DangPhi"<<endl;
                    for (int j = 0; j < danhSachChiBo[i].soDangVien; j++){
                        DangVien &dv = danhSachChiBo[i].danhSachDangVien[j];
                        int tuoiDang = 2022 - dv.nam;
                        cout << left << setw(10) << dv.soTheDV
                             << left << setw(20) << dv.tenDangVien
                             << left << setw(15) << to_string(dv.ngay) + "-" + to_string(dv.thang) + "-" + to_string(dv.nam)
                             << left << setw(10) << tuoiDang
                             << left << setw(10) << dv.chucVuDang
                             << left << setw(10) << fixed << setprecision(2) << dv.tienPhuCap
                             << left << setw(10) << fixed << setprecision(2) << dv.luong
                             << left << setw(10) << fixed << setprecision(2) << dv.dangPhi
                             << endl;
                        }
                    }
                    cout << "\nTong luong cac chi bo: " << fixed << setprecision(2) << tongLuongCacChiBo << endl;
                    cout << "Tong dang phi thu duoc: " << fixed << setprecision(2) << tongDangPhiThuDuoc << endl;
                    cout << "Tong nop cap tren: " << fixed << setprecision(2) << nopCapTren << endl;
                    pressAnyKey();
                    break;
                }
            }
            return 0;
        }

Nguyen Duy Khanh - 20225019 - 721019 - 20232 - IT3040:
Nhap so chi bo: 1
Nguyen Duc Duy - 20210275 - 727639 - 2022.2 - IT3040:
**     CHUONG TRINH QUAN LY CHi BO - DANG VIEN     **
********************MENU*****************************
**     1. Nhap cac Chi bo                          **
**     2. In ket qua ds Chi bo Dang vien           **
**     0. Thoat                                    **
*****************************************************
Nhap lua chon: 1

Ban da chon nhap danh sach cac chi bo
Nhap thong tin chi bo thu 1:
Nhap ten chi bo: ABCD

So dang vien: 1

Nhap danh sach dang vien:
Dang vien thu 1
So the: 123

Ten dang vien: Khanh

Ngay vao dang:  Ngay: 20
        Thang: 6
        Nam: 2020

Luong: 1000000

Chuc vu: Hust
Nguyen Duc Duy - 20210275 - 727639 - 2022.2 - IT3040:
**     CHUONG TRINH QUAN LY CHi BO - DANG VIEN     **
********************MENU*****************************
**     1. Nhap cac Chi bo                          **
**     2. In ket qua ds Chi bo Dang vien           **
**     0. Thoat                                    **
*****************************************************
Nhap lua chon: 2

Ban da chon xuat DS chi bo
-----------------------------------------------------------------------------------------------Ten chi bo: ABCD
So dang vien: 1
Tong luong: 1000000.00
Tong thu dang phi: 10000.00
Tong nop dang phi cap tren: 3000.00
Tong tro cap chuc vu: 0.00
Bang bang thu dang phi:
sothe     HotenDV             Ngayvaodang    Tuoidang  Chucvu    Trocap    Luong     DangPhi
123       Khanh               20-6-2020      2         Hust      0.00      1000000.0010000.00

Tong luong cac chi bo: 1000000.00
Tong dang phi thu duoc: 10000.00
Tong nop cap tren: 3000.00

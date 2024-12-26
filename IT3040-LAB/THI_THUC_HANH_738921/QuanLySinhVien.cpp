#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

struct MonHoc{
    int soTinChi;
    int soTinChiLT;
    int soTinChiTH, soTinChiBT;
    double soTinChiHocPhi;
    string maMonHoc;
    string loaiGio;
    double hocPhi;
    string khoiLuong;
};

struct SinhVien{
    string ten;
    int soMonHoc;
    vector<MonHoc> danhSachMonHoc;
    int soTienMotTinChi;
    double soTienDaNop;
    double soTienPhaiDong;
    double soTienConThieu;
    string tinhTrangHocPhi;
};

void pressAnyKey(){
    cout << "Nhap phim bat ky de tiep tuc..." << endl;
    getch();
    system("cls");
}

void nhapDanhSachMonHoc(vector<MonHoc> &danhSachMonHoc, int soMonHoc, int soTienMotTinChi, double &tongTienPhaiDong){
    for (int i = 0; i < soMonHoc; i++){
        MonHoc monHoc;
        cout << "Mon hoc thu " << i + 1 << ": ";
        cout << "\nMa mon hoc: ";
        cin >> monHoc.maMonHoc;
        cout << "\nSo tin chi: ";
        cin >> monHoc.soTinChi;
        if (monHoc.soTinChi != 6 && monHoc.soTinChi != 12){
            cout << "\n Nhap tin chi LT: ";
            cin >> monHoc.soTinChiLT;
            cout << "\n Nhap tin chi BT: ";
            cin >> monHoc.soTinChiBT;
            cout << "\n Nhap tin chi TH: ";
            cin >> monHoc.soTinChiTH;
            if (monHoc.soTinChiLT != 0 && monHoc.soTinChiBT != 0 && monHoc.soTinChiTH != 0){
                monHoc.loaiGio = "LT-BT-TH";
            } else if (monHoc.soTinChiLT != 0 && monHoc.soTinChiBT != 0 && monHoc.soTinChiTH == 0){
                monHoc.loaiGio = "LT-BT";
            } else if (monHoc.soTinChiLT != 0 && monHoc.soTinChiBT == 0 && monHoc.soTinChiTH != 0){
                monHoc.loaiGio = "LT-TH";
            }
        } else {
            if (monHoc.soTinChi == 6){
                monHoc.soTinChiTH = 12;
                monHoc.soTinChiHocPhi = 18;
                monHoc.loaiGio = "DATN Cu Nhan";
                monHoc.khoiLuong = "6(0-0-12-18)";
            }
            else if (monHoc.soTinChi == 12){
                monHoc.soTinChiTH = 24;
                monHoc.soTinChiHocPhi = 36;
                monHoc.loaiGio = "DATN Ki Su";
                monHoc.khoiLuong = "12(0-0-12-24)";
            }
        }
        monHoc.khoiLuong = (to_string)(monHoc.soTinChi) + "(" + (to_string)(monHoc.soTinChiLT) + "-" + (to_string)(monHoc.soTinChiBT) + "-" + (to_string)(monHoc.soTinChiTH) +"-" +(to_string)(2 * monHoc.soTinChi)+")";
        monHoc.soTinChiHocPhi = 1.0 * monHoc.soTinChiLT + 1.0 * monHoc.soTinChiBT + 1.5 * monHoc.soTinChiTH;
        monHoc.hocPhi = monHoc.soTinChiHocPhi * 1.0 * soTienMotTinChi;
        tongTienPhaiDong += monHoc.hocPhi;
        danhSachMonHoc[i] = monHoc;
    }
}

void inDanhSachMonHoc(vector<MonHoc> danhSachMonHoc, int soMonHoc){
    for (int i = 0; i < soMonHoc; i++){
        cout << endl;
        cout << setw(30) << danhSachMonHoc[i].maMonHoc
            << setw(30) << danhSachMonHoc[i].loaiGio
            << setw(30) << danhSachMonHoc[i].khoiLuong
            << setw(30) << danhSachMonHoc[i].soTinChiHocPhi
            << setw(30) << danhSachMonHoc[i].hocPhi;
    }
}


int main(){
    cout << "Nhap so sinh vien: ";
    int soSinhVien;
    cin >> soSinhVien;
    vector<SinhVien> danhSachSinhVien(soSinhVien);
    while (true) {
        cout<<"\nchuong trinh quan li hoc phi";
        cout<<"\n1. nhap cac sinh vien va mon hoc";
        cout<<"\n2. in ds sinh vien va hoc phi cac mon";
        cout<<"\n0. thoat";
        cout<<"\nnhap lua chon cua ban: ";
        int choice;
        cin >> choice;
        if (choice == 1){
            cout << "\nBan da chon nhap danh sach sinh vien";
            for (int i = 0; i < soSinhVien; i++){
                SinhVien sinhVien;
                cout << "\nNhap thong tin sinh vien thu " << i + 1 << ": ";
                cout << "\n Ten sinh vien: ";
                cin.ignore();
                getline(cin, sinhVien.ten);
                cout << "\n So mon hoc: ";
                cin >> sinhVien.soMonHoc;
                sinhVien.danhSachMonHoc.resize(sinhVien.soMonHoc);
                cout << "\n So tien mot tin chi: ";
                cin >> sinhVien.soTienMotTinChi;
                sinhVien.soTienPhaiDong = 0;
                nhapDanhSachMonHoc(sinhVien.danhSachMonHoc, sinhVien.soMonHoc, sinhVien.soTienMotTinChi, sinhVien.soTienPhaiDong);
                cout << "\n Hoc phi da nop: ";
                cin >> sinhVien.soTienDaNop;
                if (sinhVien.soTienDaNop >= sinhVien.soTienPhaiDong){
                    sinhVien.soTienConThieu = 0;
                    sinhVien.tinhTrangHocPhi = "Da nop du";
                } else {
                    sinhVien.soTienConThieu = sinhVien.soTienPhaiDong - sinhVien.soTienDaNop;
                    sinhVien.tinhTrangHocPhi = "Con thieu";
                }
                danhSachSinhVien[i] = sinhVien;
            }
            pressAnyKey();
        } else if (choice == 2){
            cout << "\nBan da chon xuat DS Sinh vien: ";
            for (int i = 0; i < danhSachSinhVien.size(); i++){
                cout << "\n Sinh vien thu " << i + 1 << ": " << endl;
                cout << "Ten sinh vien: " << danhSachSinhVien[i].ten << endl;
                cout << "So mon hoc: " << danhSachSinhVien[i].soMonHoc << endl;
                cout << "So tien phai dong 1 Tin chi: " << danhSachSinhVien[i].soTienMotTinChi << endl;
                cout << "Phai nop: " << danhSachSinhVien[i].soTienPhaiDong << endl;
                cout << "Da nop dot 1: " << danhSachSinhVien[i].soTienDaNop << endl;
                cout << "So tien thieu: " << danhSachSinhVien[i].soTienConThieu << endl;
                cout << "Tinh trang nop hoc phi: " << danhSachSinhVien[i].tinhTrangHocPhi << endl;
                cout << "Chi tiet cac mon hoc: ";
                cout << endl;
                cout << setw(30) << "Ma mon hoc"  << setw(30) << "Loai gio" << setw(30) << "Khoi luong" << setw(30) << "So tin chi hoc phi" << setw(30) << "Hoc phi phai nop";
                inDanhSachMonHoc(danhSachSinhVien[i].danhSachMonHoc, danhSachSinhVien[i].soMonHoc);
                pressAnyKey();
            }
        } else if (choice == 0){
            cout << "\nBan da thoat khoi chuong trinh.";
            break;
        }
    }
    return 0;
}

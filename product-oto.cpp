#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct urun{
    string ad;
    string marka;
    int urun_ID;
    int maliyet;
    int fiyat;
    int stok;
};
//tek yönlü bağlı liste yapısı
struct node{
urun urun_bilgileri;
node*sonraki;
};
//depo yapısı
struct depo{
    string ad;
    string marka;
    int ID;
    int maliyet;
    int fiyat;
    string yeri;
};
struct depo_node{
    depo depo_bilgileri;
    depo_node*sonraki;
};
//arka depoya ürün kaydetme fonksiyonu
void depoya_urun_kaydet(depo_node*& bas_d, string ad, string marka, int ID, int maliyet,int fiyat, string yeri) {
     fiyat = maliyet + maliyet * 0.5;
    depo yeni_depo = {ad, marka, ID, maliyet, fiyat, yeri};
    depo_node* yeni_dugum = new depo_node;
    yeni_dugum->depo_bilgileri = yeni_depo;
    yeni_dugum->sonraki = nullptr;
    if (bas_d == nullptr) {
        bas_d = yeni_dugum;
    } else {
        depo_node* gecici = bas_d;
        while (gecici->sonraki != nullptr) {
            gecici = gecici->sonraki;
        }
        gecici->sonraki = yeni_dugum;
    }
}

bool depoda_ara(depo_node*bas_d,int ID){
    depo_node*gecici=bas_d;
    bool bulundu=false;
    while(gecici!=nullptr){
        if(gecici->depo_bilgileri.ID==ID){
            cout<<"aradığınız ürün depoda bulunmaktadır..."<<endl;
            cout<<"ürün adı: "<<gecici->depo_bilgileri.ad<<endl;
            cout<<"ürün markası: "<<gecici->depo_bilgileri.marka<<endl;
            cout<<"ürün maliyeti: "<<gecici->depo_bilgileri.maliyet<<endl;
            cout<<"ürün fiyatı: "<<gecici->depo_bilgileri.fiyat<<endl;
            cout<<"ürünün bulunduğu yer: "<<gecici->depo_bilgileri.yeri<<endl;
            bulundu=true;
            return bulundu;
        }
        gecici=gecici->sonraki;
    }
    if(!bulundu){
        cout<<"aradığınız ürün depoda bulunamadı..."<<endl;
        return bulundu;
    }
    return 0;
}
//tek yönlü kaydetme 
void urun_kaydet(node*& bas, string ad, string marka, int ID, int maliyet,int fiyat, int stok) {
   fiyat = maliyet + maliyet * 0.5; 
    urun yeni_urun = {ad, marka, ID, maliyet, fiyat, stok};
    node* yeni_dugum = new node;
    yeni_dugum->urun_bilgileri = yeni_urun;
    yeni_dugum->sonraki = nullptr;

    if (bas == nullptr) {
        bas = yeni_dugum;
    } else {
        node* gecici = bas;
        while (gecici->sonraki != nullptr) {
            gecici = gecici->sonraki;
        }
        gecici->sonraki = yeni_dugum;
    }
}
//ürün silme fonksiyonu
void urun_sil(node*& bas, int ID) {
    node* gecici = bas;
    node* onceki = nullptr;

    while (gecici != nullptr && gecici->urun_bilgileri.urun_ID != ID) {
        onceki = gecici;
        gecici = gecici->sonraki;
    }

    if (gecici == nullptr) {
        cout << "Silmek istediğiniz ürün bulunamadı..." << endl;
    } else {
        if (onceki == nullptr) {
            bas = bas->sonraki;
        } else {
            onceki->sonraki = gecici->sonraki;
        }
        delete gecici;
    }
}
int urun_guncelle(node* bas, int ID, int yeni_fiyat, int yeni_stok) {
    node* gecici = bas;
    bool bulundu = false; 

    while (gecici != nullptr) {
        if (gecici->urun_bilgileri.urun_ID == ID) {
            bulundu = true;
            cout<<"ürünün yeni fiyatını girin: "<<endl;
            cin>>yeni_fiyat;
            cout<<"ürünün stok sayısını girin: "<<endl;
            cin>>yeni_stok;
            gecici->urun_bilgileri.fiyat = yeni_fiyat;
            gecici->urun_bilgileri.stok = yeni_stok;
            cout << "Urun basariyla guncellendi." << endl;   
            break;
        }
        gecici = gecici->sonraki;
       
    }

    if (!bulundu) {
        cout << "Belirtilen ID'ye sahip bir ürün bulunamadı." << endl;
        cout<<"depoya bakmamı istiyorsanız 1 e istemiyorsanız 0 a basın:"<<endl;
        int cevap;
        cin>>cevap;
       return cevap;   //cevabı mainde if else yaptık
    }
return 0;
}
//listede ürün arama fonksiyonu
void urun_ara(node* bas, string aranan_ad,string marka) {
    node* gecici = bas;
    bool bulundu = false;

    while (gecici != nullptr) {
        if (gecici->urun_bilgileri.ad == aranan_ad&&gecici->urun_bilgileri.marka==marka) {
           cout<<"ürün  kategorisi:"<<gecici->urun_bilgileri.ad<<endl;
            cout<<"ürün markası:"<<gecici->urun_bilgileri.marka<<endl;
            if(gecici->urun_bilgileri.stok!=0){
                cout<<"ürün stoklarımızda var"<<endl;
                cout<<"stok sayısı: "<<gecici->urun_bilgileri.stok<<endl;
            }
            bulundu = true;
            break; 
        }
        gecici = gecici->sonraki;
    }

    if (!bulundu) {
        cout << "Aranan ürün bulunamadı." << endl;
    }
}
void eleman_ozellik_yazdır(node*bas,int ID){
    node*gecici=bas;
    bool bulundu=false;
 while(gecici!=nullptr){
        if(gecici->urun_bilgileri.urun_ID==ID){
            cout<<"ürün kategorisi: "<<gecici->urun_bilgileri.ad<<endl;
            cout<<"ürün markası: "<<gecici->urun_bilgileri.marka<<endl;
            cout<<"ürün ID: "<<gecici->urun_bilgileri.urun_ID<<endl;
            cout<<"ürün maliyeti: "<<gecici->urun_bilgileri.maliyet<<endl;
            cout<<"ürün fiyatı: "<<gecici->urun_bilgileri.fiyat<<endl;
            cout<<"ürün stok sayısı: "<<gecici->urun_bilgileri.stok<<endl;
            bulundu=true;
        }
        gecici=gecici->sonraki;
 }
 if(!bulundu){
    cout<<"aranan ürün bulunamadı..."<<endl;
 }
}
//tüm ürünleri yazdırma fonksiyonu
void urun_yazdır(node*bas){
    node*gecici=bas;
    if(gecici==nullptr){
        cout<<"ürün kaydı bulunmamaktadır..."<<endl;
    }
    while(gecici!=nullptr){
        cout<<gecici->urun_bilgileri.ad<<" | "<<"markası: "<<gecici->urun_bilgileri.marka<<" | "<<"ürün ID: "<<gecici->urun_bilgileri.urun_ID<<" | "<<"maliyeti: "<<gecici->urun_bilgileri.maliyet<<" | "<<"fiyatı: "<<gecici->urun_bilgileri.fiyat<<" | "<<"stok sayısı: "<<gecici->urun_bilgileri.stok<<endl;
        cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
        gecici=gecici->sonraki;
    }
}
//fiyata göre sıralama fonksiyonu
void fiyata_gore_sirala(node*& bas) {
    if (bas == nullptr || bas->sonraki == nullptr) {
        return;
    }

    node* gecici = bas;
    node* onceki = nullptr;
    node* temp = nullptr;
    bool degisiklikYapildi = true;
    while (degisiklikYapildi) {
        degisiklikYapildi = false;
        gecici = bas;
        onceki = nullptr;

        while (gecici != nullptr && gecici->sonraki != nullptr) {
            if (gecici->urun_bilgileri.fiyat > gecici->sonraki->urun_bilgileri.fiyat){
                temp = gecici->sonraki;
                gecici->sonraki = temp->sonraki;
                temp->sonraki = gecici;

                if (onceki != nullptr) {
                    onceki->sonraki = temp;
                } else {
                    bas = temp;
                }

                onceki = temp;
                degisiklikYapildi = true;
            } else {
                onceki = gecici;
                gecici = gecici->sonraki;
            }
        }
    }
    gecici = bas;
    while (gecici != nullptr) {
        cout << gecici->urun_bilgileri.ad << " | ";
        cout << "Marka: " << gecici->urun_bilgileri.marka << " | ";
        cout << "Ürün ID: " << gecici->urun_bilgileri.urun_ID << " | ";
        cout << "Maliyet: " << gecici->urun_bilgileri.maliyet <<" TL"<< " | ";
        cout << "Fiyat: " << gecici->urun_bilgileri.fiyat<<" TL" << " | ";
        cout << "Stok Sayısı: " << gecici->urun_bilgileri.stok << endl;
        cout << "---------------------------------------------------------------------------------------------------------" << endl;
        gecici = gecici->sonraki;
    }
}
void toplam_maliyet(node*bas){
    node*gecici=bas;
    int toplam_maliyet=0;
    while(gecici!=0){
        toplam_maliyet+=gecici->urun_bilgileri.maliyet;
        gecici=gecici->sonraki;
    }
    cout<<"toplam maliyet: "<<toplam_maliyet<<" TL"<<endl;
}
void fiyat_zam(node*bas){
node*gecici=bas;

    while(gecici!=nullptr){
        gecici->urun_bilgileri.fiyat*=1.10;
        cout<<gecici->urun_bilgileri.ad<<" | "<<"markası: "<<gecici->urun_bilgileri.marka<<" | "<<"yeni fiyat: "<<gecici->urun_bilgileri.fiyat<<" TL"<<endl;
        cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
        gecici=gecici->sonraki;
    }
   
}
void minimum_maliyetli_urun_yazdir(node* bas) {
    if (bas == nullptr) {
        cout << "Liste bos, minimum maliyetli urun bulunamadi." << endl;
        return;
    }

    int min_maliyet = bas->urun_bilgileri.maliyet;
    node* gecici = bas;
    while (gecici != nullptr) {
        if (gecici->urun_bilgileri.maliyet < min_maliyet) {
            min_maliyet = gecici->urun_bilgileri.maliyet;
        }
        gecici = gecici->sonraki;
    }
    gecici = bas;
    bool minimum_bulundu = false;
    while (gecici != nullptr) {
        if (gecici->urun_bilgileri.maliyet == min_maliyet) {
            if (!minimum_bulundu) {
                cout << "Minimum Maliyetli Urunlerin Bilgileri:" << endl;
                minimum_bulundu = true;
            }
            //yazdırma işlemi
            cout << "Ad: " << gecici->urun_bilgileri.ad << endl;
            cout << "Marka: " << gecici->urun_bilgileri.marka << endl;
            cout << "ID: " << gecici->urun_bilgileri.urun_ID << endl;
            cout << "Maliyet: " << gecici->urun_bilgileri.maliyet << endl;
            cout << "Fiyat: " << gecici->urun_bilgileri.fiyat << endl;
            cout << "Stok: " << gecici->urun_bilgileri.stok << endl;
            cout << "-------------------------------------" << endl;
        }
        gecici = gecici->sonraki;
    }

    if (!minimum_bulundu) {
        cout << "Listede minimum maliyete sahip urun bulunamadi." << endl;
    }
}

void max_maliyetli_urun_yazdir(node*bas){
    if(bas==nullptr){
        cout<<"liste boş, maximum maliyetli ürün bulunamadı..."<<endl;
        return;
    }
    int max_maliyet=bas->urun_bilgileri.maliyet;
    node*gecici=bas;
    while(gecici!=nullptr){
        if(gecici->urun_bilgileri.maliyet>max_maliyet){
            max_maliyet=gecici->urun_bilgileri.maliyet;
        }
        gecici=gecici->sonraki;
    }
    gecici=bas;
    bool maximum_bulundu=false;
    while(gecici!=nullptr){
        if(gecici->urun_bilgileri.maliyet==max_maliyet){
            if(!maximum_bulundu){
                cout<<"maximum maliyetli ürünlerin bilgileri:"<<endl;
                maximum_bulundu=true;
            }
            cout<<"ad: "<<gecici->urun_bilgileri.ad<<endl;
            cout<<"marka: "<<gecici->urun_bilgileri.marka<<endl;
            cout<<"ID: "<<gecici->urun_bilgileri.urun_ID<<endl;
            cout<<"maliyet: "<<gecici->urun_bilgileri.maliyet<<endl;
            cout<<"fiyat: "<<gecici->urun_bilgileri.fiyat<<endl;
            cout<<"stok: "<<gecici->urun_bilgileri.stok<<endl;
            cout<<"-------------------------------------"<<endl;
        }
        gecici=gecici->sonraki;
    }
}
//girdi olarak alınan ürüne ait aynı maliyetteki ürün sayısını bulma fonksiyonu
void ayni_maliyet(node*bas,int maliyet){
    node*gecici=bas;
    int sayac=0;
    while(gecici!=nullptr){
        if(gecici->urun_bilgileri.maliyet==maliyet){
            sayac++; //sayacı arttır
        }
        gecici=gecici->sonraki;
    }
    cout<<"girdi olarak alınan ürüne ait aynı maliyetteki ürün sayısı: "<<sayac<<endl;
}
//ürünleri dosyaya yazdırma fonksiyonu
void urunleriDosyayaYazdir(node* bas, const string& dosyaAdi) {
    ofstream dosya(dosyaAdi);
    if (!dosya.is_open()) {
        cout << "Dosya acilamadi!" << endl;
        return;
    }

    node* gecici = bas;
    while (gecici != nullptr) {
        dosya << "Ad: " << gecici->urun_bilgileri.ad << endl;
        dosya << "Marka: " << gecici->urun_bilgileri.marka << endl;
        dosya << "ID: " << gecici->urun_bilgileri.urun_ID << endl;
        dosya << "Maliyet: " << gecici->urun_bilgileri.maliyet << endl;
        dosya << "Fiyat: " << gecici->urun_bilgileri.fiyat << endl;
        dosya << "Stok: " << gecici->urun_bilgileri.stok << endl;
        dosya << "-------------------------------------" << endl;

        gecici = gecici->sonraki;
    }

    dosya.close();
    cout << "Urunler dosyaya yazdirildi: " << dosyaAdi << endl;
}
//ürünleri dosyadan okuma fonksiyonu
void urunleriDosyadanOku(node*& bas, const string& dosyaAdi) {
    ifstream dosya(dosyaAdi);
    if (!dosya.is_open()) {
        cout << "Dosya acilamadi!" << endl;
        return;
    }
    string ad, marka;
    int ID, maliyet, fiyat, stok;
    while (dosya >> ad >> marka >> ID >> maliyet >> fiyat >> stok) {
        urun_kaydet(bas, ad, marka, ID, maliyet, fiyat, stok);
    }
    dosya.close();
    cout << "Urunler dosyadan okundu: " << dosyaAdi << endl;

}

int main(){
    node*bas=nullptr;
    depo_node*bas_d=nullptr;
    depoya_urun_kaydet(bas_d,"telefon","apple",1234,15000,0,"istanbul deposu");
    depoya_urun_kaydet(bas_d,"bilgisayar","huawei",1235,20000,0,"ankara deposu");
    depoya_urun_kaydet(bas_d,"bilgisayar","MSI",1296,40000,0,"izmir deposu");
    depoya_urun_kaydet(bas_d,"televizyon","samsung",1237,30000,0,"bursa deposu");
    depoya_urun_kaydet(bas_d,"tablet","apple",1238,8000,0,"Hatay deposu");
    urun_kaydet(bas,"telefon","samsung",1324,10000,0,10);
    urun_kaydet(bas,"bilgisayar","apple",1345,20000,0,12);
    urun_kaydet(bas,"televizyon","philips",1547,30000,0,14);
    urun_kaydet(bas,"tablet","huawei",1348,8000,0,15);
    int devam=1;
    while(devam!=0){
    cout<<"MEVİTECH'e hoşgeldiniz.."<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"lütfen yapmak istediğiniz işlemi seçiniz..."<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"1-ürün kaydet"<<endl;
    cout<<"2-ürün sil"<<endl;
    cout<<"3-ürün güncelle"<<endl;
    cout<<"4-listede ürün ara"<<endl;
    cout<<"5-aranan elemanı tüm özellikleri ile yazdır"<<endl;
    cout<<"6-tüm ürünleri yazdır"<<endl;
    cout<<"7-tüm ürünlerin fiyatını küçükten büyüğe sırala"<<endl;
    cout<<"8-listede yer alan tüm ürünlerin toplam maliyetini hesapla"<<endl;
    cout<<"9-tüm ürünlere %10 zam yap"<<endl;
    cout<<"10-minimum maliyete sahip ürünü getir"<<endl;
    cout<<"11-maximum maliyete sahip ürünü getir"<<endl;
    cout<<"12- girdi olarak alınan ürüne ilişkin aynı maliyetli diğer ürünlerin toplam sayısını bul"<<endl;
    cout<<"13-tüm ürünleri dosyaya yazdır"<<endl;
    cout<<"14- dosyadan ürünleri oku"<<endl;
    cout<<"15-çıkış"<<endl;
    cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
    int secim;
    cin>>secim;
    string kategori;
    string marka;
    int ID;
    int maliyet;
    int stok;
    if(secim==1){
        int kaydet=1;
        cout<<"ürün kaydetme işlemine hoşgeldiniz..."<<endl;
        while(kaydet!=0){
                cout<<"ürünün kategorisinin adını girini: "<<endl;
                cin>>kategori;
                cout<<"ürünün markasını girin:"<<endl;
                cin>>marka;
                cout<<"ürünün ID sini girin:"<<endl;
                cin>>ID;
                cout<<"ürünün maliyetini girin:"<<endl;
                cin>>maliyet;
                cout<<"ürünün stok sayısını girin:"<<endl;
                cin>>stok;
                urun_kaydet(bas,kategori,marka,ID,maliyet,0,stok);
                cout<<"ürün başarıyla kaydedildi..."<<endl;
    cout<<"ürün kaydetmeye devam etmek istiyorsanız 1 e istemiyorsanız 0 a basın:"<<endl;
    cin>>kaydet;
        }
        cout<<"başka işlem yapmak istiyorsanız 1 e istemiyorsanız 0 a basın:"<<endl;
        cin>>devam;
    }else if(secim==2){
        int sil=1;
        cout<<"ürün silme işlemine hoşgeldiniz..."<<endl;
        while(sil!=0){
                cout<<"silmek istediğiniz ürünün ID sini girin:"<<endl;
                int ıd;
                cin>>ıd;
                urun_sil(bas,ıd);
            cout<<"ürün silmeye devam etmek istiyorsanız 1 e istemiyorsanız 0 a basın:"<<endl;
            cin>>sil;
        }
        cout<<"başka işlem yapmak istiyorsanız 1 e istemiyorsanız 0 a basın:"<<endl;
        cin>>devam;
    }else if(secim==3){
        cout<<"ürün güncelleme işlemine hoşgeldiniz..."<<endl;
                cout<<"güncellemek istediğiniz ürünün ID sini girin:"<<endl;
                int ıd;
                cin>>ıd;
                int cevap =urun_guncelle(bas,ıd,0,0);
                if(cevap==1){
                   cout<<"bizim elemanı gönderdim bakıyo şimdi.."<<endl;
                   bool var_mı=depoda_ara(bas_d,ıd);
                   if(var_mı==false){
                    cout<<"peki bu ürünü kaydetmek ister misiniz?(e/h)"<<endl;
                    char cevap2;
                    cin>>cevap2;
                    if(cevap2=='e'){
                    cout<<"ürünün kategorisini girin: "<<endl;
                    cin>>kategori;
                    cout<<"ürünün markasını girin: "<<endl;
                    cin>>marka;
                    cout<<"ürünün maliyetini girin: "<<endl;
                    cin>>maliyet;
                    cout<<"ürünün stok sayısını girin: "<<endl;
                    cin>>stok;
                    urun_kaydet(bas,kategori,marka,ıd,maliyet,0,stok);
                    }else if(cevap2=='h'){
                        cout<<"peki siz bilirsiniz..."<<endl;
                   }else{
                          cout<<"geçersiz seçim yaptınız..."<<endl;
                   }
                }else if(cevap==0){
                    cout<<"peki siz bilirsiniz..."<<endl;
                }  
        }
        cout<<"başka işlem yapmak istiyorsanız 1 e istemiyorsanız 0 a basın:"<<endl;
        cin>>devam;
    }else if(secim==4){
        cout<<"ürün arama işlemine hoşgeldiniz..."<<endl;
        int ara=1;
        while(ara!=0){
            cout<<"aradığınız ürünün adını girin:"<<endl;
            string ad;
            cin>>ad;
            cout<<"aradığınız ürünün markasını girin:"<<endl;
            string marka;
            cin>>marka;
            urun_ara(bas,ad,marka);
            cout<<"ürün aramaya devam etmek istiyorsanız 1 e istemiyorsanız 0 a basın:"<<endl;
            cin>>ara;
        }
        cout<<"başka işlem yapmak istiyorsanız 1 e istemiyorsanız 0 a basın:"<<endl;
        cin>>devam;
    }else if(secim==5){
        cout<<"ürün özelliklerini yazdırma işlemine hoşgeldiniz..."<<endl;
        int yazdir=1;
        while(yazdir!=0){
            cout<<"özelliklerini yazdırmak istediğiniz ürünün ID sini girin:"<<endl;
            int ID;
            cin>>ID;
            eleman_ozellik_yazdır(bas,ID);
            cout<<"başka bir ürünün daha özelliklerini yazdırmaya devam etmek istiyorsanız 1 e istemiyorsanız 0 a basın:"<<endl;
            cin>>yazdir;
        }
        cout<<"başka işlem yapmak istiyorsanız 1 e istemiyorsanız 0 a basın:"<<endl;
        cin>>devam;
    }else if(secim==6){
        cout<<"tüm ürünleri yazdırma işlemine hoşgeldiniz..."<<endl;
        urun_yazdır(bas);
        cout<<"başka işlem yapmak istiyorsanız 1 e istemiyorsanız 0 a basın:"<<endl;
        cin>>devam;

    }else if(secim==7){
        cout<<"tüm ürünlerin fiyatını küçükten büyüğe sıralama işlemine hoşgeldiniz..."<<endl;
        fiyata_gore_sirala(bas);
        cout<<"başka işlem yapmak istiyorsanız 1 e istemiyorsanız 0 a basın:"<<endl;
        cin>>devam;
    }else if(secim==8){
        cout<<"tüm ürünlerin toplam maliyetini hesaplama işlemine hoşgeldiniz..."<<endl;
        toplam_maliyet(bas);
        cout<<"başka işlem yapmak istiyorsanız 1 e istemiyorsanız 0 a basın:"<<endl;
        cin>>devam;
    }else if(secim==9){
        cout<<"tüm ürünlere %10 zam yapma işlemine hoşgeldiniz..."<<endl;
            fiyat_zam(bas);
        cout<<"başka işlem yapmak istiyorsanız 1 e istemiyorsanız 0 a basın:"<<endl;
        cin>>devam;
    }else if(secim==10){
        cout<<"minimum maliyete sahip ürünü getirme işlemine hoşgeldiniz..."<<endl;
              minimum_maliyetli_urun_yazdir(bas);
        cout<<"başka işlem yapmak istiyorsanız 1 e istemiyorsanız 0 a basın:"<<endl;
        cin>>devam;

    }else if (secim==11){
        cout<<"maximum maliyete sahip ürünü getirme işlemine hoşgeldiniz..."<<endl;
            max_maliyetli_urun_yazdir(bas);
        cout<<"başka işlem yapmak istiyorsanız 1 e istemiyorsanız 0 a basın:"<<endl;
        cin>>devam;

    }else if (secim==12){
        cout<<"girdi olarak alınan ürüne ilişkin aynı maliyetli diğer ürünlerin toplam sayısını bulma işlemine hoşgeldiniz..."<<endl;
        int bul=1;
        while(bul!=0){
                cout<<" aynı maliyetteki ürünlerin sayısını bulmak istediğiniz ürünün maliyetini girin:"<<endl;
                int maliyet;
                cin>>maliyet;
                ayni_maliyet(bas,maliyet);
            cout<<"başka bir ürünü daha bulmaya devam etmek istiyorsanız 1 e istemiyorsanız 0 a basın:"<<endl;
            cin>>bul;
        }
        cout<<"başka işlem yapmak istiyorsanız 1 e istemiyorsanız 0 a basın:"<<endl;
        cin>>devam;

    }else if (secim==13){
        cout<<"tüm ürünleri dosyaya yazdırma işlemine hoşgeldiniz..."<<endl;
                urunleriDosyayaYazdir(bas,"urunler.txt");
        cout<<"başka işlem yapmak istiyorsanız 1 e istemiyorsanız 0 a basın:"<<endl;
        cin>>devam;

    }else if (secim==14){
        cout<<"dosyadan ürünleri okuma işlemine hoşgeldiniz..."<<endl;
        urunleriDosyadanOku(bas,"urunler.txt");
        cout<<"başka işlem yapmak istiyorsanız 1 e istemiyorsanız 0 a basın:"<<endl;
        cin>>devam;

    }else if (secim==15){     
        cout<<"çıkış yapılıyor..."<<endl;
        devam=0;

    }else{
        cout<<"geçersiz seçim yaptınız... tekrar deneyin..."<<endl;
        devam=1;
    }
    }
    return 0;
}
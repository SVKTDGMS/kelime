
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string tire_yildiz_kelime_manipulasyon(string girilen_kelime) // Tireli ve yıldızlı girilen komutlardaki aranan esas kelimenin oluşturulması.
{
    string temp;
    for (int m = 3; m < girilen_kelime.size() - 1; m++) // Oluşturulan geçici string e tirelerden, yıldızlardan ve komut harfinden arındırılmış aranan kelimenin yazılması.
    {
        temp = temp + girilen_kelime[m];
    }
    return temp;
}

string kelime_manipulasyon(string girilen_kelime) // Tire ve yıldız olmayan komut için aranan esas kelimenin oluşturulması.
{
    string temp;
    for (int m =2 ; m < girilen_kelime.size(); m++) // Oluşturulan geçici string e komut harfinden arındırılmış aranan kelimenin yazılması.
    {
        temp = temp + girilen_kelime[m];
    }
    return temp;
}

void dosya_yazma(string degistirilmis_string , string dosya_ismi) // Her çağırıldığında text te yapılan değişikliği dosya üzerine yazan fonksiyon.
{
    string isim = dosya_ismi;
    ofstream out(isim);
    out << degistirilmis_string;
    out.close();
}

int kelime_sayi_bul(string given_string, string aranacak_kelime) // Aranılan tam bir kelimenin sayısının bulunması.
{
    int kelime_pozisyon = 0;
    int count = 0;
    int sola;
    int saga;
    int sol_count = 0;
    int sag_count = 0;

    kelime_pozisyon = given_string.find(aranacak_kelime); // Aranan kelimenin text ten çevirilmiş string içerisindeki pozisyonun bulunması.

basla:

    kelime_pozisyon = given_string.find(aranacak_kelime);

    if (kelime_pozisyon < 0) // Döngünün sonunda artık string içerisinde aranan kelime kalmadıysa, kelime sayısına dönmek için döngü sonuna gidilmesi.
    {
        goto son;
    }

    sola = kelime_pozisyon - 1;
    saga = kelime_pozisyon + aranacak_kelime.size();

    while (given_string[sola] != ' ') // Manipule edilmiş aranan esas kelimenin solunda boşluk hariç kaç karakter olduğunun bulunması.
    {
        sol_count++;
        sola--;
    }

    while (given_string[saga] != ' ') // Manipule edilmiş aranan esas kelimenin sağında boşluk hariç kaç karakter olduğunun bulunması.
    {
        sag_count++;
        saga++;
    }

    if (sol_count == 0 && sag_count == 0) // Aranan kelimenin tire ve yıldız bulundurmadan tam bir kelime olduğunun kontrolü ve sayım yapılması.
    {
        given_string[kelime_pozisyon] = ' '; // Kelime sayısı bulunurken dosya üzerinde değişiklik yapılmayacağından, döngüde tekrar karşılaşılmaması için bulunan bir kelimenin sayısı alındıktan sonra kelimenin bozulması.
        count++;
        sol_count = 0;
        sag_count = 0;
        goto basla;
    }
    else
    {
        given_string[kelime_pozisyon] = ' '; // Kelime sayısı bulunurken dosya üzerinde değişiklik yapılmayacağından, döngüde tekrar karşılaşılmaması için bulunan bir kelimenin sayısı alındıktan sonra kelimenin bozulması.
        sag_count = 0;
        goto basla;
    }

son:
    return count;
}

int tire_kelime_sayi_bul(string given_string, string aranacak_kelime) // Aranılan tireli bir kelimenin sayısının bulunması.
{
    int kelime_pozisyon = 0;
    int count = 0;
    int sola;
    int saga;
    int sol_count = 0;
    int sag_count = 0;
    
    kelime_pozisyon = given_string.find(aranacak_kelime); // Aranan kelimenin text ten çevirilmiş string içerisindeki pozisyonun bulunması.

    basla:

    kelime_pozisyon = given_string.find(aranacak_kelime);

    if(kelime_pozisyon < 0) // Döngünün sonunda artık string içerisinde aranan kelime kalmadıysa, kelime sayısına dönmek için döngü sonuna gidilmesi.
    {
        goto son;
    }
    
    sola = kelime_pozisyon - 1;
    saga = kelime_pozisyon + aranacak_kelime.size();

    while (given_string[sola] != ' ') // Manipule edilmiş aranan esas kelimenin solunda boşluk hariç kaç karakter olduğunun bulunması.
    {
        sol_count++;
        sola--;
    }

    while (given_string[saga] != ' ') // Manipule edilmiş aranan esas kelimenin sağında boşluk hariç kaç karakter olduğunun bulunması.
    {
        sag_count++;
        saga++;
    }

    if (sol_count == 1 && sag_count == 1) // Aranılan kelimenin sağında ve solunda tek bir karakter olduğunun kontrolü ve kelime sayımının yapılması.
    {
        given_string[kelime_pozisyon] = ' '; // Döngü içerisinde tekrar karşılaşmamak için kelimenin bozulması.
        count++;
        sol_count = 0;
        sag_count = 0;
        goto basla;
    }
    else 
    {
        given_string[kelime_pozisyon] = ' '; // Döngü içerisinde tekrar karşılaşmamak için kelimenin bozulması.
        sol_count = 0;
        sag_count = 0;
        goto basla;
    }

    son:
    return count;
}


int yildiz_kelime_sayi_bul(string given_string, string aranacak_kelime) // Aranılan yıldızlı bir kelimenin sayısının bulunması.
{
    int kelime_pozisyon = 0;
    int count = 0;
    int sola;
    int saga;
    int sol_count = 0;
    int sag_count = 0;

    kelime_pozisyon = given_string.find(aranacak_kelime); // Text içerisinde aranan kelimenin pozisyonunun bulunması.

basla:

    kelime_pozisyon = given_string.find(aranacak_kelime);

    if (kelime_pozisyon < 0)
    {
        goto son;
    }
 
    sola = kelime_pozisyon - 1;
    saga = kelime_pozisyon + aranacak_kelime.size();

    while (given_string[sola] != ' ') // Kelime solundaki boşluklar hariç karakter sayısı bulunması.
    {
        sol_count++;
        sola--;
    }

    while (given_string[saga] != ' ') // Kelime sağındaki boşluklar hariç karakter sayısının bulunması.
    {
        sag_count++;
        saga++;
    }

    if (sol_count == 0 && sag_count == 0) // Kelimenin sağından ve solundaki karakter sayılarının karşılaştırılması.
    {
        given_string[kelime_pozisyon] = ' ';
        sol_count = 0;
        sag_count = 0;
        goto basla;
    }

    if (sol_count == 1 && sag_count == 1)
    {
        given_string[kelime_pozisyon] = ' ';
        sol_count = 0;
        sag_count = 0;
        goto basla;
    }

    else
    {
        given_string[kelime_pozisyon] = ' ';
        count++;
        sol_count = 0;
        sag_count = 0;
        goto basla;
    }

    son:
    return count;
}


string kelime_degistir(string given_string, string degisecek_kelime, string yeni_kelime) // Aranan tam bir kelimenin yeni kelime ile değiştirilmesi.
{
    int kelime_pozisyon = 0;
    int count = 0;
    int sola;
    int saga;
    int sol_count = 0;
    int sag_count = 0;
    string temp_string;

    kelime_pozisyon = given_string.find(degisecek_kelime);

    if (kelime_pozisyon < 0)
    {
        cout << "Error! Word was not found. Word count is: ";
        exit(EXIT_FAILURE);
    }

basla:

    kelime_pozisyon = given_string.find(degisecek_kelime);
       
    if (kelime_pozisyon < 0)
    {
        given_string.erase(given_string.begin()+0);
        temp_string = temp_string + given_string;
        goto son;
    }

    sola = kelime_pozisyon - 1;
    saga = kelime_pozisyon + degisecek_kelime.size();

    while (given_string[sola] != ' ')
    {
        sol_count++;
        sola--;
    }

    while (given_string[saga] != ' ')
    {
        sag_count++;
        saga++;
    }

    if (sol_count == 0 && sag_count == 0)
    {
        given_string = given_string.erase(kelime_pozisyon , degisecek_kelime.size());
        given_string = given_string.insert(kelime_pozisyon , yeni_kelime);
        sol_count = 0;
        sag_count = 0;
        goto basla;
    }
    else
    {
        for (int i = 1; i < kelime_pozisyon + degisecek_kelime.size() + sag_count; i++) // Geçici bir string oluşturulup kelime bir kere bulunduktan sonra o kelime dahil orayakadar olan kısmın geçici string e yazılması ve bu kısmın esas stringden silinmesi.
        {                                                                               // Böylelikle dögüde esas string içerisinde bu kelimeya tekrar rastlanmayacak ve değişime tekrar takılmadan program ilerleyebilecektir.
            temp_string = temp_string + given_string[i];
        }

        given_string = given_string.erase(0, kelime_pozisyon + degisecek_kelime.size() + sag_count - 1); // Geçici stringe yazma işlemi gerçekleştikten sonra oraya kadar olan kısmın esas stringden silinmesi.
        sol_count = 0;
        sag_count = 0;
        goto basla;
    }

son:
    return temp_string;
}


string tire_kelime_degistir(string given_string , string degisecek_kelime , string yeni_kelime) // Aranan tireli bir kelimenin yeni kelime ile değiştirilmesi. 
{
    int kelime_pozisyon = 0;
    int count = 0;
    int sola;
    int saga;
    int sol_count = 0;
    int sag_count = 0;
    string temp_string;

    kelime_pozisyon = given_string.find(degisecek_kelime);

    if (kelime_pozisyon < 0)
    {
        cout << "Error! Word was not found. Word count is: ";
        exit(EXIT_FAILURE);
    }

basla:

    kelime_pozisyon = given_string.find(degisecek_kelime);

    if (kelime_pozisyon < 0)
    {
        given_string.erase(given_string.begin() + 0);
        temp_string = temp_string + given_string;
        goto son;
    }

    sola = kelime_pozisyon - 1;
    saga = kelime_pozisyon + degisecek_kelime.size();

    while (given_string[sola] != ' ')
    {
        sol_count++;
        sola--;
    }

    while (given_string[saga] != ' ')
    {
        sag_count++;
        saga++;
    }

    if (sol_count == 1 && sag_count == 1)
    {
        given_string = given_string.erase(kelime_pozisyon -1 , degisecek_kelime.size() + 2);
        given_string = given_string.insert(kelime_pozisyon - 1, yeni_kelime);
        sol_count = 0;
        sag_count = 0;
        goto basla;
    }
    else
    {
        for (int i = 1; i < kelime_pozisyon + degisecek_kelime.size() + sag_count; i++)
        {
            temp_string = temp_string + given_string[i];
        }
        
        given_string = given_string.erase(0, kelime_pozisyon + degisecek_kelime.size() + sag_count -1);
        sol_count = 0;
        sag_count = 0;
        goto basla;
    }

son:
    return temp_string;
}


string yildiz_kelime_degistir(string given_string, string degisecek_kelime, string yeni_kelime) // Aranılan yıldızlı bir kelimenin yeni kelime ile değiştirilmesi.
{
    int kelime_pozisyon = 0;
    int count = 0;
    int sola;
    int saga;
    int sol_count = 0;
    int sag_count = 0;
    string temp_string;

    kelime_pozisyon = given_string.find(degisecek_kelime);

    if (kelime_pozisyon < 0)
    {
        cout << "Error! Word was not found. Word count is: ";
        exit(EXIT_FAILURE);
    }

basla:

    kelime_pozisyon = given_string.find(degisecek_kelime);

    if (kelime_pozisyon < 0)
    {
        given_string.erase(given_string.begin() + 0);
        temp_string = temp_string + given_string;
        goto son;
    }

    sola = kelime_pozisyon - 1;
    saga = kelime_pozisyon + degisecek_kelime.size();

    while (given_string[sola] != ' ')
    {
        sol_count++;
        sola--;
    }

    while (given_string[saga] != ' ')
    {
        sag_count++;
        saga++;
    }

    if (sol_count == 0 && sag_count == 0)
    {
        for (int i = 1; i < kelime_pozisyon + degisecek_kelime.size() + sag_count; i++)
        {
            temp_string = temp_string + given_string[i];
        }

        given_string = given_string.erase(0, kelime_pozisyon + degisecek_kelime.size() + sag_count - 1);
        sol_count = 0;
        sag_count = 0;
        goto basla;
    }

    if (sol_count == 1 && sag_count == 1)
    {
        for (int i = 1; i < kelime_pozisyon + degisecek_kelime.size() + sag_count; i++)
        {
            temp_string = temp_string + given_string[i];
        }

        given_string = given_string.erase(0, kelime_pozisyon + degisecek_kelime.size() + sag_count - 1);
        sol_count = 0;
        sag_count = 0;
        goto basla;
    }
    else
    {
        given_string = given_string.erase(kelime_pozisyon - sol_count, degisecek_kelime.size() + sol_count + sag_count);
        given_string = given_string.insert(kelime_pozisyon - sol_count, yeni_kelime);
        sol_count = 0;
        sag_count = 0;
        goto basla;
    }

son:

    return temp_string;
}


string kelime_sil(string given_string, string silinecek_kelime) // Aranılan tam bir kelimenin silinmesi.
{
    int kelime_pozisyon = 0;
    int count = 0;
    int sola;
    int saga;
    int sol_count = 0;
    int sag_count = 0;
    string temp_string;

    kelime_pozisyon = given_string.find(silinecek_kelime);

    if (kelime_pozisyon < 0)
    {
        cout << "Error! Word was not found. Word count is: ";
        exit(EXIT_FAILURE);
    }

basla:

    kelime_pozisyon = given_string.find(silinecek_kelime);

    if (kelime_pozisyon < 0)
    {
        given_string.erase(given_string.begin() + 0);
        temp_string = temp_string + given_string;
        goto son;
    }

    sola = kelime_pozisyon - 1;
    saga = kelime_pozisyon + silinecek_kelime.size();

    while (given_string[sola] != ' ')
    {
        sol_count++;
        sola--;
    }

    while (given_string[saga] != ' ')
    {
        sag_count++;
        saga++;
    }

    if (sol_count == 0 && sag_count == 0)
    {
        given_string = given_string.erase(kelime_pozisyon, silinecek_kelime.size() + 1);
        sol_count = 0;
        sag_count = 0;
        goto basla;
    }
    else
    {
        for (int i = 1; i < kelime_pozisyon + silinecek_kelime.size() + sag_count; i++)
        {
            temp_string = temp_string + given_string[i];
        }

        given_string = given_string.erase(0, kelime_pozisyon + silinecek_kelime.size() + sag_count - 1);
        sol_count = 0;
        sag_count = 0;
        goto basla;
    }

son:
    return temp_string;
}


string tire_kelime_sil(string given_string, string silinecek_kelime) // Aranılan tireli bir kelimenin silinmesi.
{
    int kelime_pozisyon = 0;
    int count = 0;
    int sola;
    int saga;
    int sol_count = 0;
    int sag_count = 0;
    string temp_string;

    kelime_pozisyon = given_string.find(silinecek_kelime);

    if (kelime_pozisyon < 0)
    {
        cout << "Error! Word was not found. Word count is: ";
        exit(EXIT_FAILURE);
    }

basla:

    kelime_pozisyon = given_string.find(silinecek_kelime);

    if (kelime_pozisyon < 0)
    {
        given_string.erase(given_string.begin() + 0);
        temp_string = temp_string + given_string;
        goto son;
    }

    sola = kelime_pozisyon - 1;
    saga = kelime_pozisyon + silinecek_kelime.size();

    while (given_string[sola] != ' ')
    {
        sol_count++;
        sola--;
    }

    while (given_string[saga] != ' ')
    {
        sag_count++;
        saga++;
    }

    if (sol_count == 1 && sag_count == 1)
    {
        given_string = given_string.erase(kelime_pozisyon - 1, silinecek_kelime.size() + 3);
         sol_count = 0;
        sag_count = 0;
        goto basla;
    }
    else
    {
        for (int i = 1; i < kelime_pozisyon + silinecek_kelime.size() + sag_count; i++)
        {
            temp_string = temp_string + given_string[i];
        }

        given_string = given_string.erase(0, kelime_pozisyon + silinecek_kelime.size() + sag_count - 1);
        sol_count = 0;
        sag_count = 0;
        goto basla;
    }

son:
    return temp_string;
}


string yildiz_kelime_sil(string given_string, string silinecek_kelime)  //Aranılan yıldızlı bir kelimenin silinmesi.
{
    int kelime_pozisyon = 0;
    int count = 0;
    int sola;
    int saga;
    int sol_count = 0;
    int sag_count = 0;
    string temp_string;

    kelime_pozisyon = given_string.find(silinecek_kelime);

    if (kelime_pozisyon < 0)
    {
        cout << "Error! Word was not found. Word count is: ";
        exit(EXIT_FAILURE);
    }

basla:

    kelime_pozisyon = given_string.find(silinecek_kelime);

    if (kelime_pozisyon < 0)
    {
        given_string.erase(given_string.begin() + 0);
        temp_string = temp_string + given_string;
        goto son;
    }

    sola = kelime_pozisyon - 1;
    saga = kelime_pozisyon + silinecek_kelime.size();

    while (given_string[sola] != ' ')
    {
        sol_count++;
        sola--;
    }

    while (given_string[saga] != ' ')
    {
        sag_count++;
        saga++;
    }

    if (sol_count == 0 && sag_count == 0)
    {
        for (int i = 1; i < kelime_pozisyon + silinecek_kelime.size() + sag_count; i++)
        {
            temp_string = temp_string + given_string[i];
        }

        given_string = given_string.erase(0, kelime_pozisyon + silinecek_kelime.size() + sag_count - 1);
        sol_count = 0;
        sag_count = 0;
        goto basla;
    }

    if (sol_count == 1 && sag_count == 1)
    {
        for (int i = 1; i < kelime_pozisyon + silinecek_kelime.size() + sag_count; i++)
        {
            temp_string = temp_string + given_string[i];
        }

        given_string = given_string.erase(0, kelime_pozisyon + silinecek_kelime.size() + sag_count - 1);
        sol_count = 0;
        sag_count = 0;
        goto basla;
    }
    else
    {
        given_string = given_string.erase(kelime_pozisyon - sol_count, silinecek_kelime.size() + sol_count + sag_count + 1);
        sol_count = 0;
        sag_count = 0;
        goto basla;
    }

son:
     return temp_string;
}


int main()
{
    string line, text;
    string filename, komut;
    string degistirilmis_string;
    string sonstr;
    string kelime, yeni_kelime;
    char komut_type, bosluk_kontrol, ilk_karakter, son_karakter;
    int sayi = 0;

    cout << "Give filename: "; // Dosya ismi alınması uyarısı.

basla:

    getline(cin, filename); // Kullanıcıdan konsol aracılığı ile dosya isminin alınması.
    ifstream fin(filename.c_str()); // Dosyanın bulunması.

    if (!fin) //Dosyanın bulunduğunun kontrolü ve aksi durumda hata verilmesi. Ardından yeni dosya ismi istenmesi
    {
        cout << "Hata! Dosya bulunamadi. Yeni dosya ismi giriniz. " << endl;
        goto basla;
    }

    while (!fin.eof()) // Verilen dosyanın tamamının, geri yazılmadan önce manipule ediilmesi için bir string olarak alınması.
    {
        getline(fin, line);
        sonstr = sonstr + "\n" + ' ' + line;
    }

    degistirilmis_string = sonstr;

komut_gir:

    cout << "Komut giriniz: "; // Kullanıcıdan komut beklenmesi uyarısı.
    getline(cin, komut); // Konsol aracılığı ile kullanıcıdan komut alınması.
    komut_type = komut[0]; // Switch de kullanılmak amacıyla girilen komut yazısından sadece komutu belli eden harfin alınması.
    bosluk_kontrol = komut[1]; // Hata verebilmek amacıyla komut harfi ile kelime arasında boşluk kontrolü yapmak için aradaki karakterin alınması.
    ilk_karakter = komut[2]; // Komutun tireli veya yıldızlı olduğunu kontrol etmek amacıyla komut karakteri ve boşluk hariç ilk karakterin alınması.
    son_karakter = komut[komut.size() - 1]; // Komutun tireli veya yıldızlı olduğunu kontrol etmek amacıyla son karakterin alınması.

    switch (komut_type) // Komut seçimi.
    {
    case 'F':
        if (bosluk_kontrol != ' ') // F komutundan sonra boşluk yoksa hata verilmesi.
        {
            cout << "Hatali komut. Yeni komut giriniz. ";
            goto komut_gir;
        }

        if (ilk_karakter == '-' && son_karakter == '-') // Tireli F komutu kontrolü
        {
            kelime = tire_yildiz_kelime_manipulasyon(komut); // Kelimenin manipule edilip varsa tire veya yıldızlardan arındırılması.
            sayi = tire_kelime_sayi_bul(sonstr, kelime); // Komuta ait fonksiyonun çağırılması.
            cout << "Aranan kelime sayisi = " << sayi << ". Yeni komut bekleniyor. ";
            goto komut_gir; // Komut gerçekleştirdikten sonra yeni komut beklenmesi.
        }

        if (ilk_karakter == '*' && son_karakter == '*') // yıldızlı F komutu kontrolü.
        {
            kelime = tire_yildiz_kelime_manipulasyon(komut);
            sayi = yildiz_kelime_sayi_bul(sonstr, kelime);
            cout << "Aranan kelime sayisi = " << sayi << ". Yeni komut bekleniyor. ";
            goto komut_gir;
        }

        // Tire ve yıldız yoksa sade kelime üzerinden işlem yapılması
        kelime = kelime_manipulasyon(komut); 
        sayi = kelime_sayi_bul(sonstr, kelime);
        cout << "Aranan kelime sayisi = " << sayi << ". Yeni komut bekleniyor. ";
        goto komut_gir;

        break;

    case 'R':
        if (bosluk_kontrol != ' ') // R komutundan sonra boşluk yoksa hata verilmesi.
        {
            cout << "Hatali komut. Yeni komut giriniz. ";
            goto komut_gir;
        }

        if (ilk_karakter == '-' && son_karakter == '-') // Tireli R komutu kontrolü
        {
            kelime = tire_yildiz_kelime_manipulasyon(komut);
            cout << "Yeni kelimeyi giriniz. ";
            getline(cin, yeni_kelime);
            degistirilmis_string = tire_kelime_degistir(degistirilmis_string, kelime, yeni_kelime);
            dosya_yazma(degistirilmis_string, filename);
            cout << "Kelimeler basari ile degistirildi. Yeni komut bekleniyor. ";
            break;
        }
        else
        {
            if (ilk_karakter == '*' && son_karakter == '*') // Yıldızlı R komutu kontrolü
            {
                kelime = tire_yildiz_kelime_manipulasyon(komut);
                cout << "Yeni kelimeyi giriniz. ";
                getline(cin, yeni_kelime);
                degistirilmis_string = yildiz_kelime_degistir(degistirilmis_string, kelime, yeni_kelime);
                dosya_yazma(degistirilmis_string, filename);
                cout << "Kelimeler basari ile degistirildi. Yeni komut bekleniyor. ";
                break;
            }

            // Tire ve yıldız yoksa sade kelime üzerinden işlem yapılması
            kelime = kelime_manipulasyon(komut);
            cout << "Yeni kelimeyi giriniz. ";
            getline(cin, yeni_kelime);
            degistirilmis_string = kelime_degistir(degistirilmis_string, kelime, yeni_kelime);
            dosya_yazma(degistirilmis_string, filename);
            cout << "Kelimeler basari ile degistirildi. Yeni komut bekleniyor. ";
            break;
        }
        

    case 'D':
        if (bosluk_kontrol != ' ')
        {
            cout << "Hatali komut. Yeni komut giriniz. ";
            goto komut_gir;
        }

        if (ilk_karakter == '-' && son_karakter == '-') // Tireli D komutu kontrolü.
        {
            kelime = tire_yildiz_kelime_manipulasyon(komut);
            degistirilmis_string = tire_kelime_sil(sonstr, kelime);
            dosya_yazma(degistirilmis_string, filename);
            cout << "Kelimeler basari ile silindi. Yeni komut bekleniyor. ";
            goto komut_gir;
        }

        if (ilk_karakter == '*' && son_karakter == '*') // Yıldızlı D komutu kontrolü.
        {
            kelime = tire_yildiz_kelime_manipulasyon(komut);
            degistirilmis_string = yildiz_kelime_sil(sonstr, kelime);
            dosya_yazma(degistirilmis_string, filename);
            cout << "Kelimeler basarı ile silindi. Yeni komut bekleniyor. ";
            goto komut_gir;
        }

        // Tire ve yıldız yoksa sade kelime üzerinden işlem yapılması
        kelime = kelime_manipulasyon(komut);
        degistirilmis_string = kelime_sil(sonstr, kelime);
        dosya_yazma(degistirilmis_string, filename);
        cout << "Kelimeler basarı ile silindi. Yeni komut bekleniyor. ";
        goto komut_gir;

        break;

    default:
        cout << "Hatali komut. Yeni komut giriniz. ";
        goto komut_gir;
    }

    goto komut_gir;

    return 0;
}




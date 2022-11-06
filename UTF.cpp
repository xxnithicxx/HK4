#include <regex>
#include <iostream>
#include <locale>
#include <codecvt>
using namespace std;

string UTF8ToASCII(string name)
{
    wstring_convert<codecvt_utf8<wchar_t>> conv;
    wstring wstr = conv.from_bytes(name);

    // Using regex to replace all UTF-8 characters with ASCII characters
    wregex charA(L"[àáảạãâầấẩậẫăằắẳặẵÀÁẢẠÃÂẦẤẨẬẪĂẰẮẲẶẴ]");
    wregex charE(L"[èéẻẹẽêềếểệễÈÉẺẸẼÊỀẾỂỆỄ]");
    wregex charI(L"[ìíỉịĩÌÍỈỊĨ]");
    wregex charO(L"[òóỏọõôồốổộỗơờớởợỡÒÓỎỌÕÔỒỐỔỘỖƠỜỚỞỢỠ]");
    wregex charU(L"[ùúủụũưừứửựữÙÚỦỤŨƯỪỨỬỰỮ]");
    wregex charY(L"[ỳýỷỵỹỲÝỶỴỸ]");
    wregex charD(L"[đĐ]");

    wstr = regex_replace(wstr, charA, L"a");
    wstr = regex_replace(wstr, charE, L"e");
    wstr = regex_replace(wstr, charI, L"i");
    wstr = regex_replace(wstr, charO, L"o");
    wstr = regex_replace(wstr, charU, L"u");
    wstr = regex_replace(wstr, charY, L"y");
    wstr = regex_replace(wstr, charD, L"d");

    // Convert wstring to string
    string str(wstr.begin(), wstr.end());
    return str;
}

string toString(wstring name)
{
    // Convert wstring to string
    string str(name.begin(), name.end());
    return str;
}

wstring toWString(string name)
{
    // Convert string to wstring
    wstring wstr(name.begin(), name.end());
    return wstr;
}

int main()
{
    string name = "Nguyễn Phúc Thịnh, Nguyễn Thị Ngọc Trâm, Nguyễn Thị Uyễn Nhi, Dương Trường Bình, Ý, Đạt";
    cout << UTF8ToASCII(name) << endl;

    return 0;
}
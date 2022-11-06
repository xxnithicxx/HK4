#include "FakeEmail.h"

FakeEmail::FakeEmail()
{
    // Load email
    ifstream emailFile("Resource\\email.txt");
    string temp;
    if (emailFile.is_open())
    {
        while (getline(emailFile, temp))
        {
            _$email.push_back(temp);
        }
    }
}

string FakeEmail::UTF8ToASCII(string name)
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

string FakeEmail::next(string fullName)
{
    // Get random email
    string email = _$email[RNG::instance()->next(_$email.size() - 1)];
    stringstream ss;
    string firstName, middleName, lastName;

    int count = 0;
    for (int i = 0; i < fullName.length(); i++)
    {
        if (fullName[i] == ' ' || i == (fullName.length() - 1))
        {
            switch (count)
            {
            case 0:
                firstName = fullName.substr(0, i);
                firstName = UTF8ToASCII(firstName);
                count++;
                break;
            case 1:
                middleName = fullName.substr(firstName.length() + 2, i - firstName.length() - 2);
                middleName = UTF8ToASCII(middleName);
                count++;
                break;
            case 2:
                lastName = fullName.substr(firstName.length() + middleName.length() + 5, i - firstName.length() - middleName.length() - 3);
                lastName = UTF8ToASCII(lastName);
                count++;
                break;
            default:
                break;
            }
        }
    }

    ss << (char)(firstName[0] + 32) << (char)(middleName[0] + 32);
    for (int i = 0; i < lastName.length(); i++)
    {
        ss << (char)(lastName[i + 1] + 32);
    }
    ss << '@' << email;

    return ss.str();
}
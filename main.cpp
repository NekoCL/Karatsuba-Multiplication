#include <iostream>
//#include <string>
//#include <sstream>
//#include <bits/stdc++.h>
//#include <algorithm>
//#include <cmath>
using namespace std;

string addition(string I1, string I2, int B) {
    int longer_number;
    int carry = 0;
    int temp_result;
    int temp_res_base;
    int a;
    int b;

    string temp_str_res = "";
    string result = "";

    int length_of_I1 = I1.length();
    int length_of_I2 = I2.length();
    int length_diff;

    //Equalize array lengths and add leading 0's
    if ( I1.length() >= I2.length() ) {
        longer_number = I1.length();
        length_diff = longer_number-length_of_I2;
        for ( int i = 0; i < length_diff; i++ ) {
            I2.insert(0, "0");
        }
    } else {
        longer_number = I2.length();
        length_diff = longer_number-length_of_I1;
        for ( int i = 0; i < length_diff; i++ ) {
            I1.insert(0, "0");
        }
    }

    //Reverse the arrays
    for ( int i = 0; i < longer_number/2; i++ ) {
        swap( I1[i], I1[longer_number-i-1] );
        swap( I2[i], I2[longer_number-i-1] );
    }

    //Perform addition
    for ( int i = 0; i < longer_number; i++ ) {
        a = I1[i]-'0';
        b = I2[i]-'0';
        temp_result = a + b + carry;

        if ( temp_result >= B ) {
            temp_res_base = temp_result-B;
            temp_str_res = std::to_string(temp_res_base);
            result.append(temp_str_res);
            carry = 1;
        } else {
            temp_str_res = std::to_string(temp_result);
            result.append(temp_str_res);
            carry = 0;
        }
    }

    if ( carry >= 1 ) {
        result.append("1");
    }

    int res_length = result.length();

    //Reverse the result back to normal position
    for ( int i = 0; i < res_length/2; i++) {
        swap( result[i], result[res_length-i-1] );
    }

    return result;
}

string subtraction(string I1, string I2, int B) {
    int longer_number;
    int carry = 0;
    int temp_result;
    int temp_res_base;
    int a;
    int b;

    string temp_str_res = "";
    string result = "";

    int length_of_I1 = I1.length();
    int length_of_I2 = I2.length();
    int length_diff;

    //Equalize array lengths and add leading 0's
    if ( I1.length() >= I2.length() ) {
        longer_number = I1.length();
        length_diff = longer_number-length_of_I2;
        for ( int i = 0; i < length_diff; i++ ) {
            I2.insert(0, "0");
        }
    } else {
        longer_number = I2.length();
        length_diff = longer_number-length_of_I1;
        for ( int i = 0; i < length_diff; i++ ) {
            I1.insert(0, "0");
        }
    }

    //Reverse the arrays
    for ( int i = 0; i < longer_number/2; i++ ) {
        swap( I1[i], I1[longer_number-i-1] );
        swap( I2[i], I2[longer_number-i-1] );
    }

    //Perform subtraction
    for ( int i = 0; i < longer_number; i++ ) {
        a = I1[i]-'0';
        b = I2[i]-'0';
        temp_result = a - b - carry;

        if ( temp_result < 0 ) {
            temp_res_base = temp_result+B;
            temp_str_res = std::to_string(temp_res_base);
            result.append(temp_str_res);
            carry = 1;
        } else {
            temp_str_res = std::to_string(temp_result);
            result.append(temp_str_res);
            carry = 0;
        }
    }

    if ( carry >= 1 ) {
        result.append("9");
    }

    int res_length = result.length();

    //Reverse the result back to normal position
    for ( int i = 0; i < res_length/2; i++) {
        swap( result[i], result[res_length-i-1] );
    }

    result.erase(0, min(result.find_first_not_of('0'), result.size()-1));

    return result;
}

string division(string dividee, int B) {
    int dividing_section = dividee[0]-'0';
    int divisions = 0;
    string div_res = "";

    for ( int i = 0; dividing_section < B; i++) {
        dividing_section = 10*dividing_section + (dividee[1+i]-'0');
        divisions++;
    }

    while ( divisions < dividee.size() ){
        div_res += (dividing_section / B)+'0';
        dividing_section = 10*(dividing_section % B) + (dividee[++divisions]-'0');
    }

    if ( div_res.length() == 0 ) {
        return "0";
    } else {
        return div_res;
    }

}

int modul(string modulee, int B) {
    int mod_res = 0;

    for ( int i = 0; i < modulee.length(); i++ ) {
        mod_res = (10*mod_res + (int)modulee[i] - '0') % B;
    }

    return mod_res;
}

string karamulti(string I1,string  I2, int B) {
    int longer_number;
    int kara_res_int;

    string kara_result = "";

    int length_of_I1 = I1.length();
    int length_of_I2 = I2.length();
    int length_diff;

    //Equalize array lengths and add leading 0's
    if ( I1.length() >= I2.length() ) {
        longer_number = I1.length();
        length_diff = longer_number-length_of_I2;
        for ( int i = 0; i < length_diff; i++ ) {
            I2.insert(0, "0");
        }
    } else {
        longer_number = I2.length();
        length_diff = longer_number-length_of_I1;
        for ( int i = 0; i < length_diff; i++ ) {
            I1.insert(0, "0");
        }
    }

    string temp_kara_result = "";
    if ( longer_number <= 1 ) {
        kara_res_int = ( I1[0]-'0' ) * ( I2[0]-'0' );
        kara_result = to_string(kara_res_int);
        return kara_result;
    } else {
        //Splitting the numbers
        string a1 = I1.substr(0, longer_number/2);
        string a0 = I1.substr(longer_number/2, longer_number-longer_number/2);
        string b1 = I2.substr(0, longer_number/2);
        string b0 = I2.substr(longer_number/2, longer_number-longer_number/2);

        string add_a0a1 = addition(a0, a1, B);
        string add_b0b1 = addition(b0, b1, B);

        //Compute the products recursively until they are single digits
        string p0 = karamulti(a0, b0, B);
        string p1 = karamulti(add_a0a1, add_b0b1, B);
        string p2 = karamulti(a1, b1, B);
        string palt = subtraction(p1, addition(p2, p0, B), B);

        //Add 0's to align the products for addition
        int aligner = longer_number-longer_number/2;

        for (int i = 0; i < 2*aligner; i++) {
            p2.append("0");
        }

        for (int i = 0; i < aligner; i++) {
            palt.append("0");
        }

        string term1 = p2;
        string term2 = palt;
        string term3 = p0;

        kara_result = addition( addition(term1, term2, B), term3, B);
        kara_result.erase(0, min(kara_result.find_first_not_of('0'), kara_result.size()-1));

        return kara_result;
    }

}


int main() {
    string I1, I2;
    int B;
    int n_max = 100;

    cin >> I1 >> I2 >> B;

//    //This loop runs when incorrect inputs are made
//    while ( I1.length() > n_max || I1.find_first_not_of("0123456789") != std::string::npos || I2.length() > n_max || I2.find_first_not_of("0123456789") != std::string::npos || B < 2 || B > 10 ) {
//        if ( I1.length() > n_max ) {
//            cout << "The 1st integer must have less than 100 digits." << endl;
//        }
//        if ( I1.find_first_not_of("0123456789") != std::string::npos ) {
//            cout << "The 1st integer must be a (positive) number." << endl;
//        }
//        if ( I2.length() > n_max ) {
//            cout << "The 2nd integer must have less than 100 digits." << endl;
//        }
//        if ( I2.find_first_not_of("0123456789") != std::string::npos ) {
//            cout << "The 2nd integer must be a (positive) number." << endl;
//        }
//        if ( B < 2 || B > 10 ) {
//            cout << "The 3rd integer must be between 2 and 10." << endl;
//        }
//        cout << "Please re-enter 3 positive integers: ";
//        cin >> I1 >> I2 >> B;
//    }

    string B_str = std::to_string(B);
    string I1_based;
    string I2_based;

    string addition_result = addition(I1, I2, B);

    if ( B < 10 && B > 2 ) {
        string I1_copy[n_max*n_max];
        string I2_copy[n_max*n_max];
        string B_powered[n_max];
        string new_B = "1";
        string temp_ka = "";

        //Create array of B indices
        for ( int i = 0; i < n_max; i++) {
            B_powered[i] = new_B;
            new_B = karamulti(new_B, B_str, 10);
        }

        for ( int i = 0; i < I1.length(); i++) {
            I1_copy[i] = "0";
        }

        //Convert I1, I2 to base 10
        temp_ka = I1.substr(I1.length()-1);
        I1_copy[I1.length()-1] = karamulti(temp_ka, B_powered[0], 10);
        I1_based = I1_copy[I1.length()-1];

        for ( int j = 0; j < I1.length()-1; j++) {
            temp_ka = I1.at(I1.length()-2-j);
            I1_copy[I1.length()-2-j] = karamulti(temp_ka, B_powered[1+j], 10);
            I1_based = addition(I1_copy[I1.length()-2-j], I1_based, 10);
        }

        temp_ka = I2.substr(I2.length()-1);
        I2_copy[I2.length()-1] = karamulti(temp_ka, B_powered[0], 10);
        I2_based = I2_copy[I2.length()-1];

        for ( int j = 0; j < I2.length()-1; j++) {
            temp_ka = I2.at(I2.length()-2-j);
            I2_copy[I2.length()-2-j] = karamulti(temp_ka, B_powered[1+j], 10);
            I2_based = addition(I2_copy[I2.length()-2-j], I2_based, 10);
        }

        //Convert result from base 10 if base is not 10
        string kara_base10 = karamulti(I1_based, I2_based, 10);
        string kara_final = "";
        string temp_kara_str;
        string div_res = "";
        int kara_base10_whole_len = 2*kara_base10.length();

        for ( int i = 0; i < kara_base10_whole_len; i++ ) {
            int kara_digit = modul(kara_base10, B);
            temp_kara_str = std::to_string(kara_digit);
            kara_final.insert(0, temp_kara_str);
            kara_base10 = division(kara_base10, B);
        }

        int kara_digit = modul(kara_base10, B);
        temp_kara_str = std::to_string(kara_digit);
        kara_final.insert(0, temp_kara_str);

        kara_final.erase(0, min(kara_final.find_first_not_of('0'), kara_final.size()-1));

        cout << addition_result << " " << kara_final << endl;

    } else {
        cout << addition_result << " " << karamulti(I1, I2, B) << endl;
    }

    return 0;
}



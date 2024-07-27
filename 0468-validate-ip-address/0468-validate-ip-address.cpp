#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string validIPAddress(string IP) {
        if (IP.empty())
            return "Neither";

        if (IP.find('.') != string::npos)
            return validateIPv4(IP);

        if (IP.find(':') != string::npos)
            return validateIPv6(IP);

        return "Neither";
    }

private:
    string validateIPv4(const string& ip) {
        if (ip.front() == '.' || ip.back() == '.')
            return "Neither";

        vector<string> components = split(ip, '.');

        if (components.size() != 4)
            return "Neither";

        for (const string& comp : components) {
            if (comp.empty() || comp.size() > 3 || (comp[0] == '0' && comp.size() > 1))
                return "Neither";

            for (char ch : comp) {
                if (!isdigit(ch))
                    return "Neither";
            }

            int num = stoi(comp);
            if (num < 0 || num > 255)
                return "Neither";
        }

        return "IPv4";
    }

    string validateIPv6(const string& ip) {
        if (ip.front() == ':' || ip.back() == ':')
            return "Neither";

        vector<string> components = split(ip, ':');
        if (components.size() != 8)
            return "Neither";

        for (const string& comp : components) {
            if (comp.empty() || comp.size() > 4)
                return "Neither";

            for (char ch : comp) {
              ch = tolower(ch); 
              if((ch < '0' || ch > '9') && ch != 'a' && ch != 'b' && ch != 'c' && ch != 'd' && ch != 'e' && ch != 'f')
                return "Neither";
            }
        }

        return "IPv6";
    }
     vector<string> split(const string& s, char delimiter) {
        vector<string> tokens;
        string token;
        istringstream tokenStream(s);
        while (getline(tokenStream, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }

 
};



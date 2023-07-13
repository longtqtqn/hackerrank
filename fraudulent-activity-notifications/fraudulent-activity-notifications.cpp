/**
 * Code by longtqtqn
 * Using default template read/write console of hackerrank :p
 */
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

map<int, int> m;

double getMedian(int d) {
    int count = 0;
    int remember = -1;
    int mid = d / 2;

    for (auto const& pair : m)
    {
        count += pair.second;
        if (count > mid) {
            if (d % 2 == 1 || remember == -1) {
                return pair.first;
            }
            return (remember + pair.first) / 2.0;
        }
        if (count == mid && d % 2 == 0) {
            remember = pair.first;
        }
    }
    return 0;
}

int activityNotifications(vector<int> expenditure, int d) {
    int rs = 0;
    for (int i = 0; i <= 200; ++i) {
        m[i] = 0;
    }

    for (int i = 0; i < d; ++i) {
        ++m[expenditure[i]];
    }
    for (int i = d; i < expenditure.size(); ++i) {
        double median = getMedian(d);
        int exp = expenditure[i];
        if (exp >= median * 2) {
            ++rs;
        }
        --m[expenditure[i - d]];
        ++m[exp];
    }

    return rs;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int d = stoi(first_multiple_input[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split(rtrim(expenditure_temp_temp));

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

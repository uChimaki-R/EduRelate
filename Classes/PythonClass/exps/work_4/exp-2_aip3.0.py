import requests
import json
import csv
import time

headers = {
    'User-Agent': 'Mozilla/5.0 (Linux; Android 6.0; Nexus 5 Build/MRA58N) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/78.0.3904.108 Mobile Safari/537.36',
    'Referer': 'http://fundf10.eastmoney.com/jjjz_160706.html'
}


def get_html(url, writer):
    html = requests.get(url, headers=headers)
    html_text = html.text
    print(html_text)
    start = html_text.find('{"Data":{"LSJZList"')
    json_data = json.loads(html_text[start:-1])
    netvalues = json_data['Data']['LSJZList']

    for row in netvalues:
        fsrq = row['FSRQ']
        dwjz = row['DWJZ']
        ljjz = row['LJJZ']
        jzzzl = row['JZZZL']
        print(fsrq, dwjz, ljjz, jzzzl)
        writer.writerow([fsrq, dwjz, ljjz, jzzzl])


if __name__ == '__main__':
    with open(f'exp-2_output.csv', 'w', newline='', encoding='utf-8') as csvfile:
        keys = ['FSRQ', 'DWJZ', 'LJJZ', 'JZZZL']
        writer = csv.writer(csvfile)
        writer.writerow(keys)

        for i in range(1, 101):
            url = 'http://api.fund.eastmoney.com/f10/lsjz?' \
                  'callback=jQuery183015088915834593553_1586246635664&' \
                  'fundCode=160706&pageIndex={}&pageSize=20&' \
                  'startDate=&endDate=&_=1586246635678'.format(i)
            print('当前输出第{}页'.format(i))
            get_html(url, writer)
            print("存储完成第{}页, 休息一秒".format(i))
            time.sleep(1)

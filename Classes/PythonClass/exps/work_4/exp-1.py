import json
import csv


with open('beijing_aqi.json', 'r', encoding='utf-8') as f:
    dict_list = json.load(f)
    headers = dict_list[0].keys()

    # 对字典列表按照'pm2_5'键进行升序排序
    sorted_dict_list = sorted(dict_list, key=lambda x: x['pm2_5'])

    with open('exp-1_output.csv', 'w', newline='', encoding='utf-8') as csvfile:
        # 使用csv.DictWriter将排序后的字典列表写入csv文件
        writer = csv.DictWriter(csvfile, fieldnames=headers)

        writer.writeheader()

        for row in sorted_dict_list:
            writer.writerow(row)

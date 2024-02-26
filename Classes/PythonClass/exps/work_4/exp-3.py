from lxml import etree
import csv


with open('Dylan_van_Baarle.txt', 'r') as f:
    Html = etree.HTML(f.read())

    # 找到包含数据的部分
    datas = Html.xpath('//*[@type="text/javascript"]/text()')[1]

    # 切割出数据部分
    pos = datas.find("function resizePublicFileViewer()")
    datas = datas[:pos].strip()[28:-1]
    # null、false、true在python中没定义, 换成字符串
    datas = datas.replace('null', "'null'").replace('false', "'false'").replace('true', "'true'")

    # 转换为字典
    dic = eval(datas)
    workoutSampleList = dic["workoutDetailData"]['workoutSampleList']
    print(workoutSampleList.keys())  # dict_keys(['isEventBased', 'channelSet', 'samples'])

    # 具体数据位置
    samples = workoutSampleList['samples']

    # 数据总量
    print(len(samples))  # 20199

    # 每个数据的具体数据分类
    print(samples[0].keys())  # dict_keys(['evt', 'ms', 'values'])

    # values中还有9个数据, 和channelSet中的名称数量相同, 是一一对应的
    print(len(samples[0]['values']))  # 9
    channelSet = workoutSampleList['channelSet']
    print(channelSet)
    # ['heartRate', 'speed', 'power', 'elevation', 'temperature', 'cadence', 'distance', 'positionLat', 'positionLong']
    print(len(channelSet))  # 9

    # 要写入的csv的表头
    headers = [
        'evt', 'ms', 'heartRate', 'speed', 'power', 'elevation',
        'temperature', 'cadence', 'distance', 'positionLat', 'positionLong'
    ]

    # 拼接values中的数值为键值对所使用的键列表
    value_headers = [
        'heartRate', 'speed', 'power', 'elevation','temperature',
        'cadence', 'distance', 'positionLat', 'positionLong'
    ]

    # 组装每行数据
    rows = []
    for sample in samples:
        row = dict()
        # 独立存两个单独的数据
        row['evt'] = sample['evt']
        row['ms'] = sample['ms']

        # 存values中的数据
        for key, value in zip(value_headers, sample['values']):
            row[key] = value

        rows.append(row)
    print(rows)

    # 写入文件
    with open('train_DvB.csv', 'w', newline='', encoding='utf-8') as ff:
        writer = csv.DictWriter(ff, fieldnames=headers)
        writer.writeheader()
        for row in rows:
            writer.writerow(row)

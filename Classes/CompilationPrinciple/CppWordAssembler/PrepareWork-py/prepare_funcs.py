def get_key_words():
    with open('keywords_format.txt', 'w') as fout:
        with open('keywords.txt', 'r') as fin:
            cnt = 1
            out_line = ""
            for line in fin:
                out_line += f'"{line.strip()}", '
                cnt += 1
                if cnt % 6 == 0:
                    fout.write(out_line+'\n')
                    out_line = ""


if __name__ == '__main__':
    get_key_words()

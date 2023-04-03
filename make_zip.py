# encoding: utf-8
import argparse
from yoshi.private import MakeZip

if __name__ == '__main__':
    APP_NAME="execcommandcom"
    
    #ZIPに入れるファイル
    SOURCES=[
        "x64/Debug/ExecCommandCOM.dll",
        "x64/Debug/register.bat",
        "x64/Debug/unregister.bat",
        "readme.md",
        "sample",
    ]
    #引数
    parser = argparse.ArgumentParser()
    parser.add_argument('-k','--keep_tmp',action='store_true',
        help="指定された場合、一時フォルダを削除しない。一時フォルダにはzipファイルの中身が入っている"
    )

    args=parser.parse_args()
    obj = MakeZip()
    errs=obj.make_zip(APP_NAME,SOURCES,args.keep_tmp)
    if len(errs)>0:
        print("===== errors =====")
        for err in errs:
            print(err)
    else:
        print(APP_NAME+".zip created.")
        
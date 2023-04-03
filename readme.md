# ExecCommand

## これは何か
COMオブジェクトです。ATLを使用。クライアントプログラムは64bitのみ対応しています。  

### **DOS窓を出さずにCUIコマンドを起動する**  
LibreOfficeのマクロからCUIコマンドを起動して標準出力を得るためにWindowsScriptingHostのCOMオブジェクト(wscript.shell)を使用していました。しかしこれだと起動時にDOS窓が表示されるため、うっとおしい。  
そのため、C#でコマンドを起動するCOMオブジェクトを作成しました。  
コマンドの終了を待ち、標準出力・標準エラーを取得します。DOS窓は表示しません。

### **プロセス間通信**
親プロセスから子プロセスに（ExcelからPerlなど）、コマンドラインで渡すのが難しい大きな文字列を渡すためにプロセス間通信をサポートしました。プロセスが親子関係である必要はありません。

## 開発・動作確認環境
Windows11 64bit  
Microsoft VisualStudio Community 2022 64bit  
.NET Framework 7.0  
LibleOffice7.4.5.1 64bit  

## インストール
### **ファイルをダウンロードして展開**
execcommand.zipをクリック→Download

### **DLLのレジストリへの登録・登録解除**
register.batを管理者で実行する。

### サンプルファイル
#### **sample/test.ods**
LibreOfficeCalcファイル。マクロからCOMオブジェクトを呼び出しています。  

#### **test.ps1**
powershellスクリプト。calcファイルのマクロから起動され、COMオブジェクトを呼び出しています。


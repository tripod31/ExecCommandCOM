$oData = New-Object -ComObject SharedData
#�W���o�͂ɓǂݎ�������L�f�[�^���o��
#-NoNewLine:���s�R�[�h���o�͂��Ȃ�
Write-Host -NoNewline $oData.GetData()
#���L�f�[�^���Z�b�g
$oData.SetData("_RETURN_")

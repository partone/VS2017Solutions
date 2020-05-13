'Made by Eric Parton
'Miracle Tonic Pear

Imports System.IO

Public Class Form1
    'Set path text when user selects it
    Private Sub directoryBrowse_Click(sender As Object, e As EventArgs) Handles directoryBrowse.Click
        If (FolderBrowserDialog1.ShowDialog() = DialogResult.OK) Then
            directoryName.Text = FolderBrowserDialog1.SelectedPath
        End If
    End Sub

    'String builder for name format
    Private Sub Help_Click(sender As Object, e As EventArgs) Handles Help.Click
        MessageBox.Show("Click on these buttons to establish your naming format." + vbCrLf + "If you understand the format this application uses, feel free to type directly in to the text field." + vbCrLf + vbCrLf + "Button colour scheme:" + vbCrLf + "Red: Track information" + vbCrLf + "Green: User information" + vbCrLf + "Blue: File information", "What are these buttons?")
    End Sub

    Private Sub title_Click(sender As Object, e As EventArgs) Handles title.Click
        namingFormat.AppendText("{title}")
    End Sub

    Private Sub genre_Click(sender As Object, e As EventArgs) Handles genre.Click
        namingFormat.AppendText("{genre}")
    End Sub

    Private Sub year_Click(sender As Object, e As EventArgs) Handles year.Click
        namingFormat.AppendText("{year}")
    End Sub

    Private Sub track_Click(sender As Object, e As EventArgs) Handles track.Click
        namingFormat.AppendText("{track}")
    End Sub

    Private Sub created_Click(sender As Object, e As EventArgs) Handles created.Click
        namingFormat.AppendText("{created}")
    End Sub

    Private Sub size_Click(sender As Object, e As EventArgs) Handles size.Click
        namingFormat.AppendText("{size}")
    End Sub

    Private Sub artist_Click(sender As Object, e As EventArgs) Handles artist.Click
        namingFormat.AppendText("{artist}")
    End Sub

    Private Sub album_Click(sender As Object, e As EventArgs) Handles album.Click
        namingFormat.AppendText("{album}")
    End Sub

    Private Sub duration_Click(sender As Object, e As EventArgs) Handles duration.Click
        namingFormat.AppendText("{duration}")
    End Sub

    Private Sub rating_Click(sender As Object, e As EventArgs) Handles rating.Click
        namingFormat.AppendText("{rating}")
    End Sub

    Private Sub modified_Click(sender As Object, e As EventArgs) Handles modified.Click
        namingFormat.AppendText("{modified}")
    End Sub

    Private Sub bitrate_Click(sender As Object, e As EventArgs) Handles bitrate.Click
        namingFormat.AppendText("{bitrate}")
    End Sub


    Private Sub runBatchRenamerHandler(sender As Object, e As EventArgs) Handles runBatchRenamer.Click
        'If an invalid name has been given
        If namingFormat.Text.Contains("<") Or namingFormat.Text.Contains(">") Or namingFormat.Text.Contains(":") Or namingFormat.Text.Contains("*") Or namingFormat.Text.Contains("|") Or namingFormat.Text.Contains("?") Or namingFormat.Text.Contains("\") Or namingFormat.Text.Contains("/") Then
            MessageBox.Show("You can't include the following characters in the name: < > : "" * | ? / \", "Oh no!")
            Exit Sub
        End If

        'If a directory hasn't been given
        If directoryName.Text.Equals("No directory selected") Then
            MessageBox.Show("You haven't selected a directory", "Oh no!")
            Exit Sub
        End If

        'If a format hasn't been given
        If namingFormat.Text.Equals("") Then
            MessageBox.Show("You must define a naming format", "Oh no!")
            Exit Sub
        End If

        Dim result As Integer = MessageBox.Show("This will write over your current file names but will not change the file metadata.  Are you sure?", "Just double checking!", MessageBoxButtons.YesNo)
        If result = DialogResult.No Then
            Exit Sub
        ElseIf result = DialogResult.Yes Then
            batchRenamer()
        End If
    End Sub

    'Does the renaming stuff
    Private Sub batchRenamer()
        'Get the naming format as an array
        'Dim namingFormatArray() As String
        'namingFormatArray = getNamingFormatArray()

        'Modified from https://stackoverflow.com/questions/2216101/vb-net-how-to-loop-through-a-directory-listing
        'Get the directoy name
        Dim directoryNameString As String
        directoryNameString = directoryName.Text
        Dim di As New DirectoryInfo(directoryNameString)
        'Get a reference to each file in that directory.
        Dim fiArr As FileInfo() = di.GetFiles()
        Dim fri As FileInfo

        'Loop through each file
        For Each fri In fiArr
            'Opens the file using an MP3ID3v1 API object
            Dim objMP3V1 As New MP3ID3v1(directoryNameString + "\" + fri.Name)

            'Loop round to get title
            Dim title As String
            title = getMediaTitle(objMP3V1, namingFormat.Text)
        Next fri
    End Sub

    Function getNamingFormatArray() As String()
        Dim tmpArray() As String

        tmpArray = namingFormat.Text.Split(" "c)
        Dim list As New List(Of String)
        For i As Integer = 0 To tmpArray.Length - 1
            Dim elems() As String = tmpArray(i).Split("="c)
            If elems.Length > 1 Then list.Add(elems(1).Trim) Else list.Add("")
        Next

        getNamingFormatArray = tmpArray
    End Function

    Function getMediaTitle(song As MP3ID3v1, namingFormatUnreplaced As String)
        'Holds the final name
        Dim name As String
        name = namingFormatUnreplaced
        name = name.Replace("{title}", song.Frame(MP3ID3v1.FrameTypes.Title))
        name = name.Replace("{genre}", song.Frame(MP3ID3v1.FrameTypes.Genre))
        name = name.Replace("{year}", song.Frame(MP3ID3v1.FrameTypes.Year))
        name = name.Replace("{track}", song.Frame(MP3ID3v1.FrameTypes.Track))
        name = name.Replace("{created}", song.Frame(MP3ID3v1.FrameTypes.Title))     'Hmmm
        name = name.Replace("{size}", song.Frame(MP3ID3v1.FrameTypes.Title))        'Hmmm
        name = name.Replace("{artist}", song.Frame(MP3ID3v1.FrameTypes.Artist))
        name = name.Replace("{album}", song.Frame(MP3ID3v1.FrameTypes.Album))
        name = name.Replace("{duration}", song.Frame(MP3ID3v1.FrameTypes.Title))    'Hmmm
        name = name.Replace("{rating}", song.Frame(MP3ID3v1.FrameTypes.Title))      'Hmmm
        name = name.Replace("{modified}", song.Frame(MP3ID3v1.FrameTypes.Title))    'Hmmm
        name = name.Replace("{bitrate}", song.Frame(MP3ID3v1.FrameTypes.Title))     'Hmmm

        'For i = 0 To namingArray.Length - 1
        '    Select Case namingArray(i)
        '        Case "{title}"
        '            name = name & song.Frame(MP3ID3v1.FrameTypes.Title)
        '        Case "{genre}"
        '            name = name & song.Frame(MP3ID3v1.FrameTypes.Genre)
        '        Case "{year}"
        '            name = name & song.Frame(MP3ID3v1.FrameTypes.Year)
        '        Case "{track}"
        '            name = name & song.Frame(MP3ID3v1.FrameTypes.Track)
        '        Case "{created}"
        '            name = name & song.Frame(MP3ID3v1.FrameTypes.Title) 'Hmmm
        '        Case "{size}"
        '            name = name & song.Frame(MP3ID3v1.FrameTypes.Title) 'Hmmm
        '        Case "{artist}"
        '            name = name & song.Frame(MP3ID3v1.FrameTypes.Artist)
        '        Case "{album}"
        '            name = name & song.Frame(MP3ID3v1.FrameTypes.Album)
        '        Case "{duration}"
        '            name = name & song.Frame(MP3ID3v1.FrameTypes.Title) 'Hmmm
        '        Case "{rating}"
        '            name = name & song.Frame(MP3ID3v1.FrameTypes.Title) 'Hmmm
        '        Case "{modified}"
        '            name = name & song.Frame(MP3ID3v1.FrameTypes.Title) 'Hmmm
        '        Case "{bitrate}"
        '            name = name & song.Frame(MP3ID3v1.FrameTypes.Title) 'Hmmm
        '        Case Else
        '            name = name & namingArray(i)
        '    End Select
        'Next
        name = name.Replace("?", "")

        name = System.Text.RegularExpressions.Regex.Replace(name, "[^\u0000-\u007F]", "")
        name = name.Replace("?", "q")

        Console.WriteLine(name)
        getMediaTitle = name
    End Function
End Class

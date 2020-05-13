Imports System.IO

Public Class MP3ID3v1

    ' Constructor
    Public Sub New(Optional ByVal Filename As String = "")
        MyBase.New()
        If (Filename <> "") Then Me.Filename = Filename
    End Sub

#Region " Declarations "

    ' Genres
    Public Enum Genres As Byte
        Blues = 0
        ClassicRock = 1
        Country = 2
        Dance = 3
        Disco = 4
        Funk = 5
        Grunge = 6
        HipHop = 7
        Jazz = 8
        Metal = 9
        NewAge = 10
        Oldies = 11
        Other = 12
        Pop = 13
        RnB = 14
        Rap = 15
        Reggae = 16
        Rock = 17
        Techno = 18
        Industrial = 19
        Alternative = 20
        Ska = 21
        DeathMetal = 22
        Pranks = 23
        Soundtrack = 24
        EuroTechno = 25
        Ambient = 26
        TripHop = 27
        Vocal = 28
        JazzFunk = 29
        Fusion = 30
        Trance = 31
        Classical = 32
        Instrumental = 33
        Acid = 34
        House = 35
        Game = 36
        SoundClip = 37
        Gospel = 38
        Noise = 39
        AlternRock = 40
        Bass = 41
        Soul = 42
        Punk = 43
        Space = 44
        Meditative = 45
        InstrumentalPop = 46
        InstrumentalRock = 47
        Ethnic = 48
        Gothic = 49
        Darkwave = 50
        TechnoIndustrial = 51
        Electronic = 52
        PopFolk = 53
        Eurodance = 54
        Dream = 55
        SouthernRock = 56
        Comedy = 57
        Cult = 58
        Gangsta = 59
        Top40 = 60
        ChristianRap = 61
        PopFunk = 62
        Jungle = 63
        NativeAmerican = 64
        Cabaret = 65
        NewWave = 66
        Psychadelic = 67
        Rave = 68
        Showtunes = 69
        Trailer = 70
        LoFi = 71
        Tribal = 72
        AcidPunk = 73
        AcidJazz = 74
        Polka = 75
        Retro = 76
        Musical = 77
        RocknRoll = 78
        HardRock = 79
        None = 255
    End Enum

    ' Frame types
    Public Enum FrameTypes As Byte
        Title = 0
        Artist = 1
        Album = 2
        Year = 3
        Track = 4
        Comment = 5
        Genre = 6
    End Enum

#End Region
#Region " Properties "

    ' Filename
    Private mstrFilename As String
    Public Property Filename() As String
        Get
            Return mstrFilename
        End Get
        Set(ByVal Value As String)
            Dim objFile As File
            If (objFile.Exists(Value)) Then
                mstrFilename = Value
                Refresh()
            Else
                Throw New System.IO.FileLoadException("The specified file does not exist", Value)
            End If
        End Set
    End Property

    ' TagExists
    Private mblnTagExists As Boolean
    Public ReadOnly Property TagExists() As Boolean
        Get
            Return mblnTagExists
        End Get
    End Property

    ' Frame
    Private mobjFrame(7) As Object
    Public Property Frame(ByVal FrameType As FrameTypes)
        Get
            Return mobjFrame(FrameType)
        End Get
        Set(ByVal Value)
            mobjFrame(FrameType) = Value
        End Set
    End Property

#End Region
#Region " Methods "

    ' Refresh (gets all tags from the specified file)
    Public Sub Refresh()

        ' Declarations
        Dim strTag As New String(" ", 3)
        Dim strTitle As New String(" ", 30)
        Dim strArtist As New String(" ", 30)
        Dim strAlbum As New String(" ", 30)
        Dim strYear As New String(" ", 4)
        Dim strComment As New String(" ", 28)
        Dim bytDummy As Byte
        Dim bytTrack As Byte
        Dim bytGenre As Byte

        ' Open the file
        Dim intFile As Integer = FreeFile()
        FileOpen(intFile, mstrFilename, OpenMode.Binary, OpenAccess.Read, OpenShare.LockWrite)

        ' Gets length of file
        Dim lngLOF As Long = LOF(intFile)
        If (lngLOF > 128) Then

            ' Check for the ID3v1 tag
            FileGet(intFile, strTag, lngLOF - 127, True)
            If (strTag.ToUpper <> "TAG") Then

                ' No ID3v1 tag found
                mblnTagExists = False
                mobjFrame(0) = ""
                mobjFrame(1) = ""
                mobjFrame(2) = ""
                mobjFrame(3) = ""
                mobjFrame(4) = ""
                mobjFrame(5) = ""
                mobjFrame(6) = ""

            Else

                ' ID3v1 tag found
                mblnTagExists = True

                ' Read all frames from the file
                FileGet(intFile, strTitle)
                FileGet(intFile, strArtist)
                FileGet(intFile, strAlbum)
                FileGet(intFile, strYear)
                FileGet(intFile, strComment)
                FileGet(intFile, bytDummy)
                FileGet(intFile, bytTrack)
                FileGet(intFile, bytGenre)

                ' Assign the frame content to the properties
                mobjFrame(0) = strTitle
                mobjFrame(1) = strArtist
                mobjFrame(2) = strAlbum
                mobjFrame(3) = strYear
                mobjFrame(4) = bytTrack
                mobjFrame(5) = strComment
                mobjFrame(6) = bytGenre

            End If
        End If

        ' Close the file
        FileClose(intFile)

    End Sub

    ' Update
    Public Sub Update()

        ' Declarations
        Dim strTag As New String(" ", 3)
        Dim strTitle As New String(" ", 30)
        Dim strArtist As New String(" ", 30)
        Dim strAlbum As New String(" ", 30)
        Dim strYear As New String(" ", 4)
        Dim strComment As New String(" ", 28)
        Dim bytDummy As Byte
        Dim bytTrack As Byte
        Dim bytGenre As Byte

        ' Open the file
        Dim intFile As Integer = FreeFile()
        FileOpen(intFile, mstrFilename, OpenMode.Binary, OpenAccess.ReadWrite, OpenShare.LockWrite)

        ' Gets length of file
        Dim lngLOF As Long = LOF(intFile)
        If (lngLOF > 0) Then
            If (lngLOF > 128) Then

                ' Check for an existing ID3v1 tag
                FileGet(intFile, strTag, lngLOF - 127)
                If (strTag.ToUpper <> "TAG") Then

                    ' No ID3v1 tag found, so just add one
                    Seek(intFile, lngLOF)
                    strTag = "TAG"
                    FilePut(intFile, strTag)

                End If

                ' Fix the length of the frames
                strTitle = LSet(mobjFrame(0), Len(strTitle))
                strArtist = LSet(mobjFrame(1), Len(strArtist))
                strAlbum = LSet(mobjFrame(2), Len(strAlbum))
                strYear = LSet(mobjFrame(3), Len(strYear))
                bytTrack = mobjFrame(4)
                strComment = LSet(mobjFrame(5), Len(strComment))
                bytGenre = mobjFrame(6)

                ' Write the frames to the file
                FilePut(intFile, strTitle)
                FilePut(intFile, strArtist)
                FilePut(intFile, strAlbum)
                FilePut(intFile, strYear)
                FilePut(intFile, strComment)
                FilePut(intFile, bytDummy)
                FilePut(intFile, bytTrack)
                FilePut(intFile, bytGenre)

            End If
        End If

        ' Close the file
        FileClose(intFile)

    End Sub

#End Region

End Class

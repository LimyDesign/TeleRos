#!/usr/bin/perl 
my $host="localhost";
my $datauser="utel";
my $datpass="ptel";
my $database="tel";
my $dd="-";
my $dt=":";
use Sys::Syslog;
use DBI;

sub trim {
    my $str= shift ;
    $str=~ s/^\s+//;
    $str=~ s/\s+$//;
    return $str;
}

select (STDOUT); $|++; 
select (STDIN); $|++; 
while (<STDIN>) {
    $input = $_;
    # open(MYFILE, '>>/tmp/cdr.txt');
    # print MYFILE $input;
    # close(MYFILE);
    if (length($input) == 80) {
        if ($dbh = DBI->connect("DBI:mysql:$database:$host","$datauser","$datpass")) {
            ($i1,$i2,$i3,$i4,$i5,$i6,$i7,$i8,$i9,$i10,$i11,$i12) = (trim(substr($input,0,6)),trim(substr($input,7,4)),trim(substr($input,12,4)),trim(substr($input,17,3)),trim(substr($input,21,4)),trim(substr($input,26,3)),trim(substr($input,31,10)),trim(substr($input,44,1)),trim(substr($input,47,1)),trim(substr($input,50,5)),trim(substr($input,56,18)),trim(substr($input,75,2)));
            my $a = $i1.$i2;
            $a=~ /(\d\d)(\d\d)(\d\d)(\d\d)(\d\d)/;
            $dbh->do("insert into  acccall (`date`,`time`,`code-used`,`out-crt-id`,`in-trk-code`,`in-crt-id`,`clg-num-in-tac`,`cond-code`,`frl`,`sec-dur`,`dialed-num`,`node-num` ) values ('20".$3.$dd.$2.$dd.$1." ".$4.$dt.$5."', '".$i2."', '".$i3."', '$i4' ,'$i5','$i6', '$i7', '$i8', '$i9','$i10','$i11','$i12' );");
            $dbh->disconnect();
        } else {
            syslog('info', "JRate service: can't connect database");
        }
    }
}

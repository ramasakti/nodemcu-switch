const switchingPintu = () => {
    const switchPintu = document.getElementById('switchPintu')
    if (switchPintu.checked) {
        window.location.replace('on')
    }
}

if (window.location.pathname == '/on') {
    document.getElementById('labelPintu').innerText = 'Buka'
    document.getElementById('switchPintu').setAttribute('checked', '')
    setInterval(() => {
        window.location.replace('off')
    }, 2000)
}else{
    document.getElementById('labelPintu').innerText = 'Tutup'
}
